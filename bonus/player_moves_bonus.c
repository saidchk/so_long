/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:28:58 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void	move_up(s_data *game)
{
	char	*num;
	
	num = calloc(11,1);
	if (!num)
	{
		write (1, "Error in allocation\n", 23);
		ft_free(game, game->map_len);
	}
			if (game->map[game->y][game->x] == 'P' && game->map[game->y
		- 1][game->x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.wall_ptr, 2*37,0);
		if (game->map[game->y - 1][game->x] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->number_moves++;
		game->y--;
	 //sprintf(num, "%d", game->number_moves);
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 1 , 1* 30,0xe8e8e8, "M O V E :");
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 2*40 , 1*30 ,0xe8e8e8, num);
	 free(num);
	remove_traces(game, game->keycode);
}

void	move_down(s_data *game)
{
	char	*num;
	
	num = calloc(11,1);
	if (!num)
	{
		write (1, "Error in allocation\n", 23);
		ft_free(game, game->map_len);
	}
	if (game->map[game->y][game->x] == 'P' && game->map[game->y
		+ 1][game->x] == '1')
		return ;
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.wall_ptr, 2*37,0);
		if (game->map[game->y + 1][game->x] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->number_moves++;
		game->y++;
	//sprintf(num, "%d", game->number_moves);
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 1 , 1* 30,0xe8e8e8, "M O V E :");
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 2*40 , 1*30 ,0xe8e8e8, num);
	free(num);
	remove_traces(game, game->keycode);
}

void	move_left(s_data *game)
{
	char	*num;

	num = calloc(11,1);
	if (!num)
	{
		write (1, "Error in allocation\n", 23);
		ft_free(game, game->map_len);
	}
	if (game->map[game->y][game->x] == 'P' && game->map[game->y][game->x
		- 1] == '1')
		return ;
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.wall_ptr, 2*37,0);
	
		if (game->map[game->y][game->x - 1] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
		game->number_moves++;
		game->x--;
	 //sprintf(num, "%d", game->number_moves);
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 1 , 1* 30,0xe8e8e8, "M O V E :");
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 2*40 , 1*30 ,0xe8e8e8, num);
	free(num);
	remove_traces(game, game->keycode);
}

void	move_right(s_data *game)
{
	char	*num;

	num = calloc(11,1);
	if (!num)
	{
		write (1, "Error in allocation\n", 23);
		ft_free(game, game->map_len);
	}
	if (game->map[game->y][game->x] == 'P' && game->map[game->y][game->x
		+ 1] == '1')
		return ;
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.wall_ptr, 2*37,0);
	
		if (game->map[game->y][game->x + 1] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
		game->number_moves++;
		game->x++;
	 //sprintf(num, "%d", game->number_moves);
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 1 , 1* 30,0xe8e8e8, "M O V E :");
	 mlx_string_put(game->mlx_ptr,game->window_ptr , 2*40 , 1*30 ,0xe8e8e8, num);
	remove_traces(game, game->keycode);
	free(num);
}
