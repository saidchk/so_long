/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 16:08:35 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_extension(char *file_name)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = 0;
	j = 3;
	while (file_name[i])
		i++;
	i--;
	while (i >= 0 && j >= 0)
	{
		if (file_name[i--] != ext[j--])
		{
			write(1, "Error, the name of file\n", 25);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_is_closed(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_len)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' || game->map[y][game->weight_map
				- 1] != '1')
			{
				write(1, "close the map\n", 14);
				ft_free(game, game->map_len);
			}
			if (y == 0 || y == game->map_len - 1)
				x++;
			else
				break ;
		}
		y++;
	}
}

void	flood_fill(t_data *game, int x, int y)
{
	if ((y <= 0 || y >= game->map_len) || (x <= 0 || x >= game->weight_map)
		|| game->map[y][x] == 'k' || game->map[y][x] == '.'
		|| game->map[y][x] == 'e' || game->map[y][x] == '1')
		return ;
	else
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x] = '.';
			game->counter.number_of_c--;
		}
		else if (game->map[y][x] == 'E')
		{
			game->map[y][x] = 'e';
			game->counter.number_of_e--;
		}
		else
			game->map[y][x] = 'k';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

void	check_map(char *map_name, t_data *game)
{
	int	save_value;

	game->counter.number_of_c = 0;
	game->counter.number_of_e = 0;
	game->counter.number_of_p = 0;
	game->counter_of_food = 0;
	game->size_m = 0;
	ft_check_extension(map_name);
	get_map(game, map_name);
	save_value = game->counter.number_of_c;
	ft_is_closed(game);
	flood_fill(game, game->x, game->y);
	game->map[game->y][game->x] = 'P';
	if (game->counter.number_of_c != 0 || game->counter.number_of_e != 0)
	{
		write(1, "not valide path\n", 16);
		ft_free(game, game->map_len);
	}
	game->counter.number_of_c = save_value;
}
