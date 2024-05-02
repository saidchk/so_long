/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/02 21:42:00 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_len(int fd, int *size)
{
	char	tab[1];
	int		count;

	count = 0;
	*size = 0;
	while (read(fd, tab, 1) != 0)
	{
		if (tab[0] == '\n')
		{
			(*size)++;
			count++;
		}
		(*size)++;
	}
	return (count + 1);
}
#include <stdio.h>

void	get_map(s_data *game, char *map_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error in file\n", 15);
		exit(0);
	}
	game->map_len = count_len(fd, &game->size_m);
	close(fd);
	game->map = malloc(sizeof(char *) * (game->map_len + 1));
	if (game->map == NULL)
	{
		write(1, "error in allocation\n", 21);
		ft_free(game);
	}
	game->map[game->map_len] = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error in file\n", 15);
		exit(0);
	}
	get_next_line(fd, game);
}
