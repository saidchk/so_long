/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 01:50:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_number(int num)
{
	char	n;

	if (num < 10)
	{
		n = num + 48;
		write(1, &n, 1);
		return ;
	}
	else
	{
		put_number(num / 10);
		n = (num % 10) + 48;
		write(1, &n, 1);
	}
}

void	move_up(t_data *game)
{
	if (game->map[game->y][game->x] == 'P' && game->map[game->y
		- 1][game->x] == '1')
		return ;
	if (game->map[game->y][game->x] == 'P')
	{
		if (game->map[game->y - 1][game->x] == '.')
			game->counter.number_of_c--;
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->number_moves++;
		game->y--;
		put_number(game->number_moves);
		write(1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}

void	move_down(t_data *game)
{
	if (game->map[game->y][game->x] == 'P' && game->map[game->y
		+ 1][game->x] == '1')
		return ;
	if (game->map[game->y][game->x] == 'P')
	{
		if (game->map[game->y + 1][game->x] == '.')
			game->counter.number_of_c--;
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->number_moves++;
		game->y++;
		put_number(game->number_moves);
		write(1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}

void	move_left(t_data *game)
{
	if (game->map[game->y][game->x] == 'P' && game->map[game->y][game->x
		- 1] == '1')
		return ;
	if (game->map[game->y][game->x] == 'P')
	{
		if (game->map[game->y][game->x - 1] == '.')
			game->counter.number_of_c--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
		game->number_moves++;
		game->x--;
		put_number(game->number_moves);
		write(1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}

void	move_right(t_data *game)
{
	if (game->map[game->y][game->x] == 'P' && game->map[game->y][game->x
		+ 1] == '1')
		return ;
	if (game->map[game->y][game->x] == 'P')
	{
		if (game->map[game->y][game->x + 1] == '.')
			game->counter.number_of_c--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
		game->number_moves++;
		game->x++;
		put_number(game->number_moves);
		write(1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}
