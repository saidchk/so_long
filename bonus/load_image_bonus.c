/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 18:22:05 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_null(t_img_adrr *ptr)
{
	ptr->pac_semi = NULL;
	ptr->black_wal = NULL;
	ptr->collectible_ptr = NULL;
	ptr->pac_semi_down = NULL;
	ptr->pac_semi_up = NULL;
	ptr->pac_semi_right = NULL;
	ptr->pac_semi_left = NULL;
	ptr->wall_ptr = NULL;
	ptr->pac_down = NULL;
	ptr->pac_up = NULL;
	ptr->pac_right = NULL;
	ptr->pac_left = NULL;
	ptr->ennemi_ptr = NULL;
	ptr->player_ptr = NULL;
	ptr->pac_tr = NULL;
	ptr->pac_min_tr = NULL;
	ptr->exit = NULL;
}

int	ft_check(t_img_adrr *ptr)
{
	if (!ptr->black_wal || !ptr->collectible_ptr || !ptr->ennemi_ptr
		|| !ptr->exit || !ptr->pac_down || !ptr->pac_left || !ptr->pac_right
		|| !ptr->pac_semi_down || !ptr->pac_semi_left || !ptr->pac_semi_right
		|| !ptr->pac_semi_up || !ptr->pac_up || !ptr->player_ptr
		|| !ptr->wall_ptr || !ptr->pac_semi || !ptr->pac_tr || !ptr->pac_min_tr)
	{
		write(1, "error in loading image\n", 24);
		free(ptr->black_wal);
		free(ptr->collectible_ptr);
		free(ptr->pac_semi_down);
		free(ptr->pac_semi_up);
		free(ptr->pac_semi_right);
		free(ptr->pac_semi_left);
		free(ptr->wall_ptr);
		free(ptr->pac_down);
		free(ptr->pac_up);
		free(ptr->pac_right);
		free(ptr->pac_left);
		free(ptr->ennemi_ptr);
		free(ptr->player_ptr);
		free(ptr->pac_tr);
		free(ptr->pac_min_tr);
		return (free(ptr->exit), -1);
	}
	return (1);
}

void	ft_load_image(t_data *game)
{
	int	w;
	int	h;

	game->image.pac_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_open_up.xpm", &w, &h);
	game->image.pac_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_open_left.xpm", &w, &h);
	game->image.pac_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_open_right.xpm", &w, &h);
	game->image.pac_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_open_down.xpm", &w, &h);
	game->image.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_left.xpm", &w, &h);
	game->image.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_right.xpm", &w, &h);
	game->image.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_down.xpm", &w, &h);
	game->image.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_up.xpm", &w, &h);
	game->image.player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_closed.xpm", &w, &h);
	game->image.black_wal = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/black_wal.xpm", &w, &h);
	if (ft_check(&game->image) == -1)
		ft_free(game, game->map_len);
}
