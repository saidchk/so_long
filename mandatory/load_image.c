/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 19:39:36 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_null(t_img_adrr *ptr)
{
	ptr->black_wal = NULL;
	ptr->collectible_ptr = NULL;
	ptr->pac_semi_down = NULL;
	ptr->pac_semi_up = NULL;
	ptr->pac_semi_right = NULL;
	ptr->pac_semi_left = NULL;
	ptr->wall_ptr = NULL;
	ptr->exit = NULL;
}

int	ft_check(t_img_adrr *ptr)
{
	if (!ptr->black_wal || !ptr->collectible_ptr || !ptr->exit
		|| !ptr->pac_semi_down || !ptr->pac_semi_left || !ptr->pac_semi_right
		|| !ptr->pac_semi_up || !ptr->wall_ptr)
	{
		write(1, "error in loading image\n", 24);
		return (-1);
	}
	return (1);
}

void	ft_load_image(t_data *game)
{
	int	w;
	int	h;

	set_null(&game->image);
	game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/door.xpm",
			&w, &h);
	game->image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wa.xpm", &w, &h);
	game->image.collectible_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible.xpm", &w, &h);
	game->image.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_left.xpm", &w, &h);
	game->image.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_right.xpm", &w, &h);
	game->image.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_down.xpm", &w, &h);
	game->image.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/pac_semi_up.xpm", &w, &h);
	game->image.black_wal = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/black_wal.xpm", &w, &h);
	if (ft_check(&game->image) == -1)
		ft_free(game, game->map_len);
}
