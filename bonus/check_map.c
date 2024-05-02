#include "so_long.h"

void	ft_check_extension(char *file_name)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = 0;
	j = 0;
	while (file_name[i] != '.' && file_name[i])
		i++;
	if (file_name[i] == 0)
	{
		write(1, "Error, the name of file is note valide\n", 39);
		exit(EXIT_FAILURE);
	}
	while (ext[j] || file_name[i])
	{
		if (file_name[i] != ext[j++])
		{
			write(1, "Error, the name of file is note valide\n", 39);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_is_closed(s_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_len)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' || game->map[y][game->weight_map - 1] != '1')
			{
				write(1, "close the map\n", 14);
				ft_free(game);
				exit(EXIT_FAILURE);
			}
			if (y == 0 || y == game->map_len - 1)
				x++;
			else
				break ;
		}
		y++;
	}
}

void	check_p_e_c(s_data *game, num_of_composed *size)
{
	while (game->map[size->y])
	{
		size->x = 1;
		while (game->map[size->y][size->x])
		{
			if (game->map[size->y][size->x] == 'D')
			{
				game->ennemi.x_g = size->x;
				game->ennemi.y_g = size->y;
			}
			if (game->map[size->y][size->x] == 'C')
				size->number_of_c++;
			else if (game->map[size->y][size->x] == 'P')
			{
				size->number_of_p++;
				game->x = size->x;
				game->y = size->y;
			}
			else if (game->map[size->y][size->x] == 'E')
			{
				size->number_of_e++;
				game->x_exit = size->x;
				 game->y_exit = size->y;
			}
			size->x++;
		}
		size->y++;
	}
	if (size->number_of_c < 1 || size->number_of_e != 1
		|| size->number_of_p != 1)
	{
		write(1, "error in composed\n", 18);
		 ft_free(game);
	}
}

void	flood_fill(s_data *game, int x, int y, int *count_exit)
{
	if ((y < 0 || y >= game->map_len) || (x < 0 || x >= game->weight_map)
		|| game->map[y][x] == 'k' || game->map[y][x] == '.'
		|| game->map[y][x] == 'e' || (game->map[y][x] != '0'
			&& game->map[y][x] != 'C' && game->map[y][x] != 'P'
			&& game->map[y][x] != 'E'))
		return ;
	else
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x] = '.';
			game->counter_of_food++;
		}
		else if (game->map[y][x] == 'E')
		{
			game->map[y][x] = 'e';
			(*count_exit)++;
		}
		else
			game->map[y][x] = 'k';
		flood_fill(game, x + 1, y, count_exit);
		flood_fill(game, x - 1, y, count_exit);
		flood_fill(game, x, y + 1, count_exit);
		flood_fill(game, x, y - 1, count_exit);
	}
}

void	check_map(char *map_name, s_data *game)
{
	int				count_exit;
	num_of_composed	size;

	size.number_of_c = 0;
	size.number_of_p = 0;
	size.number_of_e = 0;
	size.y = 1;
	game->counter_of_food = 0;
	count_exit = 0;
	ft_check_extension(map_name);
	get_map(game, map_name);
	ft_is_closed(game);
	check_p_e_c(game, &size);
	flood_fill(game, game->x, game->y, &count_exit);
	game->map[game->y][game->x] = 'P';
	if (game->counter_of_food != size.number_of_c || count_exit != size.number_of_e)
	{
		write(1, "not valide path\n", 16);
		ft_free(game);
		exit(EXIT_FAILURE);
	}
}
