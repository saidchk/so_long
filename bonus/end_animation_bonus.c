/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/04 14:23:36 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put(s_data *game, void *pac)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, game->y * 37);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, pac, game->x * 37,
		game->y * 37);
}

int	ft_wait(s_data *game)
{
	static int	i = 0;

	if (i > 7000)
		ft_free(game);
	if (i == 500)
		ft_put(game, &game->image.player_ptr);
	else if (i == 2000)
		ft_put(game, &game->image.pac_semi_up);
	if (i == 3500)
		ft_put(game, &game->image.pac_semi);
	else if (i == 5000)
		ft_put(game, &game->image.pac_tr);
	else if (i == 6500)
		ft_put(game, &game->image.pac_min_tr);
	i++;
	return (0);
}

void	end_animation(s_data *game)
{

	mlx_loop_hook(game->mlx_ptr, ft_wait, game);
	mlx_loop(game->mlx_ptr);
}
