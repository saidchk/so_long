/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/02 21:49:56 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"
#include <math.h>
#include <stdio.h>

void	previous_move(s_data *game)
{
	if (game->d == 'u')
		move_down_ennemi(game);
	else if (game->d == 'd')
		move_up_ennemi(game);
	else if (game->d == 'l')
		move_right_ennemi(game);
	else
		move_left_ennemi(game);
	game->d = ('d' * (game->d == 'u') + 'u' * (game->d == 'd') + 'r'
			* (game->d == 'l') + 'l' * (game->d == 'r'));
}

void	move_ennemi(s_data *game, int u, int d, int r, int l)
{
	if (u != 10000 && u <= d && u <= r && u <= l)
	{
		move_up_ennemi(game);
		game->d = 'u';
	}
	else if (l != 10000 && l <= d && l <= u && l <= r)
	{
		move_left_ennemi(game);
		game->d = 'l';
	}
	else if (d != 10000 && d <= u && d <= r && d <= l)
	{
		move_down_ennemi(game);
		game->d = 'd';
	}
	else if (r != 10000 && r <= d && r <= u && r <= l)
	{
		move_right_ennemi(game);
		game->d = 'r';
	}
	else
		previous_move(game);
}

void	move(s_data *game)
{
	int	dis[4];
	int	e_x;
	int	e_y;

	e_x = game->ennemi.x_g;
	e_y = game->ennemi.y_g;
	dis[0] = 10000;
	dis[1] = 10000;
	dis[2] = 10000;
	dis[3] = 10000;
	if (game->map[e_y - 1][e_x] != '1' && game->d != 'd')
		dis[0] = abs(e_x - game->x) + abs(e_y - 1 - game->y);
	if (game->map[e_y + 1][e_x] != '1' && game->d != 'u')
		dis[1] = abs(e_x - game->x) + abs(e_y + 1 - game->y);
	if (game->map[e_y][e_x + 1] != '1' && game->d != 'l')
		dis[2] = abs(e_x + 1 - game->x) + abs(e_y - game->y);
	if (game->map[e_y][e_x - 1] != '1' && game->d != 'r')
		dis[3] = abs(e_x - 1 - game->x) + abs(e_y - game->y);
	move_ennemi(game, dis[0], dis[1], dis[2], dis[3]);
}
