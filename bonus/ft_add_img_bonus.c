/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 20:23:28 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_traces(t_data *game, int keycode)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
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

void	ft_i(t_data *game, int keycode)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
	if (game->map[game->y][game->x] == 'D')
		end_animation(game);
	if ((keycode == 0 || keycode == 123))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_left, game->x * 37, game->y * 37);
	}
	else if ((keycode == 2 || keycode == 124))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_right, game->x * 37, game->y * 37);
	}
	else if ((keycode == 13 || keycode == 126))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_up, game->x * 37, game->y * 37);
	}
	else if ((keycode == 1 || keycode == 125))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_down, game->x * 37, game->y * 37);
	}
}

void	put_pacman(t_data *game, int keycode)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
	if (game->map[game->y][game->x] == 'D')
		end_animation(game);
	if (keycode == 0 || keycode == 123)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_left, game->x * 37, game->y * 37);
	else if (keycode == 2 || keycode == 124)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_right, game->x * 37, game->y * 37);
	else if (keycode == 13 || keycode == 126)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_up, game->x * 37, game->y * 37);
	else if (keycode == 1 || keycode == 125)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_down, game->x * 37, game->y * 37);
	else if (keycode == 30000)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.player_ptr, game->x * 37, game->y * 37);
	if (game->counter_of_food == -1 && game->x_exit == game->x
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
					game->image.player_ptr, j * 37, i * 37);
			else if (game->map[i][j] == 'D')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.ennemi_ptr, j * 37, i * 37);
			else if (game->map[i][j] == '.')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.collectible_ptr, j * 37, i * 37);
			j++;
		}
		i++;
	}
}

void	ft_add_img(t_data *game)
{
	int	w;
	int	h;

	game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/door.xpm",
			&w, &h);
	game->image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wa.xpm", &w, &h);
	game->image.ennemi_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/ghost_down2.xpm", &w, &h);
	game->image.collectible_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible.xpm", &w, &h);
	game->image.pac_tr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_tr.xpm", &w, &h);
	game->image.pac_min_tr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_min_tr.xpm", &w, &h);
	game->image.pac_semi = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi.xpm", &w, &h);
	ft_load_image(game);
	put_image(game);
}
