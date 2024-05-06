/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 22:38:31 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *game)
{
	ft_free(game, game->map_len);
	return (0);
}

void	ft_free(t_data *game, int i)
{
	if (i == -1)
		write(1, "error in allocation\n", 21);
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
	if (game->mlx_ptr != NULL && game->window_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	exit(1);
}
