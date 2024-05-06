/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 22:33:46 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	previous_move(t_data *game)
{
	if (game->d == 'u')
		move_down_ennemi(game);
	else if (game->d == 'd')
		move_up_ennemi(game);
	else if (game->d == 'l')
		move_right_ennemi(game);
	else
		move_left_ennemi(game);
}

void	move_ennemi(t_data *game, int *dis)
{
	if (dis[0] != MAX_INT && dis[0] <= dis[1] && dis[0] <= dis[2]
		&& dis[0] <= dis[3])
		move_up_ennemi(game);
	else if (dis[3] != MAX_INT && dis[3] <= dis[1] && dis[3] <= dis[0]
		&& dis[3] <= dis[2])
		move_left_ennemi(game);
	else if (dis[1] != MAX_INT && dis[1] <= dis[0] && dis[1] <= dis[2]
		&& dis[1] <= dis[3])
		move_down_ennemi(game);
	else if (dis[2] != MAX_INT && dis[2] <= dis[1] && dis[2] <= dis[0]
		&& dis[2] <= dis[3])
		move_right_ennemi(game);
	else
		previous_move(game);
}

void	move(t_data *game)
{
	int	dis[4];
	int	e_x;
	int	e_y;

	e_x = game->ennemi.x_g;
	e_y = game->ennemi.y_g;
	dis[0] = MAX_INT;
	dis[1] = MAX_INT;
	dis[2] = MAX_INT;
	dis[3] = MAX_INT;
	if (game->map[e_y - 1][e_x] != '1' && game->map[e_y - 1][e_x] != 'D'
		&& game->d != 'd')
		dis[0] = abs(e_x - game->x) + abs(e_y - 1 - game->y);
	if (game->map[e_y + 1][e_x] != '1' && game->map[e_y + 1][e_x] != 'D'
		&& game->d != 'u')
		dis[1] = abs(e_x - game->x) + abs(e_y + 1 - game->y);
	if (game->map[e_y][e_x + 1] != '1' && game->map[e_y][e_x + 1] != 'D'
		&& game->d != 'l')
		dis[2] = abs(e_x + 1 - game->x) + abs(e_y - game->y);
	if (game->map[e_y][e_x - 1] != '1' && game->map[e_y][e_x - 1] != 'D'
		&& game->d != 'r')
		dis[3] = abs(e_x - 1 - game->x) + abs(e_y - game->y);
	move_ennemi(game, dis);
}
