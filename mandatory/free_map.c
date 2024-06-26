/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 19:39:09 by schakkou         ###   ########.fr       */
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
	free(game->image.black_wal);
	free(game->image.collectible_ptr);
	free(game->image.exit);
	free(game->image.pac_semi_down);
	free(game->image.pac_semi_up);
	free(game->image.pac_semi_right);
	free(game->image.pac_semi_left);
	free(game->image.wall_ptr);
	exit(1);
}
