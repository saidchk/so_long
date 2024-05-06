/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:07:41 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

///bach  nejbed x o y mehtaj nehseb l3ard o l formul li nkhadem bach d3tini x = size - line lifih db-1 * l3ard - 1 and y = line lifih  db -1
void	ft_count_p_e_c(s_data *game, char tab, int len )
{
	if (tab == 'D')
	{
		game->ennemi.x_g = (game->size_m - 1) - (len  * game->weight_map) - len;
		game->ennemi.y_g = len ;
	}
	if (tab == 'C')
		game->counter.number_of_c++;
	else if (tab == 'P')
	{
		game->counter.number_of_p++;
		game->x = (game->size_m - 1) - (len  * game->weight_map) - len;
		game->y = len ;
	}
	else if (tab == 'E')
	{
		game->counter.number_of_e++;
		game->x_exit = (game->size_m -1) - (len  * game->weight_map) - len ;
		game->y_exit = len;
	}
	
}
int	count_len(int fd, s_data *game)
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
		if(stop == 1)
			game->weight_map++;
		game->size_m++;	
		if (tab[0] == 'P' || tab[0] == 'C' || tab[0] == 'E' || tab[0] == 'D')
			ft_count_p_e_c(game, tab[0], count);
	}
	if (game->counter.number_of_c < 1 || game->counter.number_of_e != 1 
		|| game->counter.number_of_p != 1)
	{
		write(1, "error in composed\n", 18);
		exit(0);
	}
	game->size_m += count;
	return (close(fd),count + 1);
}
void	get_map(s_data *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error in file\n", 15);
		exit(0);
	}
	game->map_len = count_len(fd, game);
	game->map = malloc(sizeof(char *) * (game->map_len + 1));
	if (game->map == NULL)
	{
		write(1, "error in allocation\n", 21);
		ft_free(game, -1);
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
