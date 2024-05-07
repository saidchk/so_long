/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 18:13:52 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_traces(t_data *game, int keycode)
{
	if (game->counter.number_of_c == 0)
		put_door(game);
	if ((keycode == 0 || keycode == 123) && game->map[game->y][game->x
		+ 1] != '.' && game->map[game->y][game->x + 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->x + 1) * 37, game->y * 37);
	}
	else if ((keycode == 2 || keycode == 124) && game->map[game->y][game->x
		- 1] != '.' && game->map[game->y][game->x - 1] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->x - 1) * 37, game->y * 37);
	}
	else if ((keycode == 13 || keycode == 126) && game->map[game->y + 1]
		[game->x] != '.' && game->map[game->y + 1][game->x] != '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, game->x * 37, (game->y + 1) * 37);
	}
	else if ((keycode == 1 || keycode == 125) && game->map[game->y - 1]
		[game->x] != '.' && game->map[game->y - 1][game->x] != '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, game->x * 37, (game->y - 1) * 37);
}

void	put_pacman(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
	if (game->keycode == 0 || game->keycode == 123)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_left, game->x * 37, game->y * 37);
	else if (game->keycode == 2 || game->keycode == 124)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_right, game->x * 37, game->y * 37);
	else if (game->keycode == 13 || game->keycode == 126)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_up, game->x * 37, game->y * 37);
	else if (game->keycode == 1 || game->keycode == 125)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_down, game->x * 37, game->y * 37);
	if (game->counter.number_of_c == 0 && game->x_exit == game->x
		&& game->y_exit == game->y)
		ft_free(game, game->map_len);
}

void	put_image(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.wall_ptr, j * 37, i * 37);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.pac_semi_left, j * 37, i * 37);
			else if (game->map[i][j] == '.')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.collectible_ptr, j * 37, i * 37);
			j++;
		}
		i++;
	}
}

void	ft_ran_img(t_data *game)
{
	ft_load_image(game);
	put_image(game);
}
