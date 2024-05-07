/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 16:48:53 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		free(game->map[i--]);
	free(game->map);
	if (game->mlx_ptr != NULL && game->window_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	free(game->image.black_wal);
	free(game->image.collectible_ptr);
	free(game->image.pac_semi_down);
	free(game->image.pac_semi_up);
	free(game->image.pac_semi_right);
	free(game->image.pac_semi_left);
	free(game->image.wall_ptr);
	free(game->image.pac_down);
	free(game->image.pac_up);
	free(game->image.pac_right);
	free(game->image.pac_left);
	free(game->image.ennemi_ptr);
	free(game->image.player_ptr);
	free(game->image.pac_tr);
	free(game->image.pac_min_tr);
	free(game->image.exit);
	free(game->image.pac_semi)
	exit(1);
}
