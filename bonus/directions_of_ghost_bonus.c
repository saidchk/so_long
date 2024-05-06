/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_of_ghost_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:05:40 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void check_collision(s_data *game, int x, int y)
{
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == 'P'
		|| game->map[game->ennemi.y_g + y][game->ennemi.x_g + x] == 'P')
	{
		if (game->map[game->ennemi.y_g + y][game->ennemi.x_g + x] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
				* 37);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.ennemi_ptr, game->ennemi.x_g * 37,
				(game->ennemi.y_g) * 37);
		end_animation(game);
		ft_free(game, game->map_len);
	}
}

void	move_up_ennemi(s_data *game)
{
	check_collision(game, 0, -1);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g - 1)
		* 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37,
			game->ennemi.y_g * 37);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
	game->ennemi.y_g--;
}

void	move_down_ennemi(s_data *game)
{
	check_collision(game, 0, 1);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.ennemi_ptr, (game->ennemi.x_g) * 37, (game->ennemi.y_g + 1)
		* 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37,
			game->ennemi.y_g * 37);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
	game->ennemi.y_g++;
}

void	move_left_ennemi(s_data *game)
{
	check_collision(game, -1, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.ennemi_ptr, (game->ennemi.x_g - 1) * 37, game->ennemi.y_g
		* 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37,
			game->ennemi.y_g * 37);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
	game->ennemi.x_g--;
}

void	move_right_ennemi(s_data *game)
{
		check_collision(game, 1, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.ennemi_ptr, (game->ennemi.x_g + 1) * 37, game->ennemi.y_g
		* 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37,
			game->ennemi.y_g * 37);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g
			* 37);
	game->ennemi.x_g++;
}
