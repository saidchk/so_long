/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 19:51:33 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_p_e_c(t_data *game, char tab, int len)
{
	if (tab != 'C' && tab != 'P' && tab != '0' && tab != 'E' && tab != '1'
		&& tab != '\n')
	{
		write(1, "Error, not valid composed\n", 27);
		exit(0);
	}
	else if (tab == 'C')
		game->counter.number_of_c++;
	else if (tab == 'P')
	{
		game->counter.number_of_p++;
		game->x = (game->size_m - 1) - (len * game->weight_map) - len;
		game->y = len;
	}
	else if (tab == 'E')
	{
		game->counter.number_of_e++;
		game->x_exit = (game->size_m - 1) - (len * game->weight_map) - len;
		game->y_exit = len;
	}
}

int	count_len(int fd, t_data *game)
{
	char	tab[1];
	int		count;
	int		stop;

	game->weight_map = 0;
	count = 0;
	stop = 1;
	while (read(fd, tab, 1) != 0)
	{
		if (tab[0] == '\n' && stop++)
			count++;
		if (stop == 1)
			game->weight_map++;
		game->size_m++;
		ft_count_p_e_c(game, tab[0], count);
	}
	if (game->counter.number_of_c < 1 || game->counter.number_of_e != 1
		|| game->counter.number_of_p != 1)
	{
		write(1, "error in composed\n", 18);
		exit(0);
	}
	game->size_m ++;
	return (close(fd), count + 1);
}

void	get_map(t_data *game, char *map_name)
{
	int		fd;
	char	*tab;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error in file\n", 15);
		exit(0);
	}
	game->map_len = count_len(fd, game);
	game->map = malloc(sizeof(char *) * (game->map_len + 1));
	if (game->map == NULL)
		ft_free(game, -1);
	game->map[game->map_len] = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error in file\n", 15);
		ft_free(game, -2);
	}
	tab = malloc(game->size_m);
	if (tab == NULL)
		ft_free(game, -1);
	get_next_line(fd, game, tab);
}
