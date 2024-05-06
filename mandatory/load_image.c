/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 22:43:16 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(s_img_adrr *ptr)
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

void	ft_load_image(s_data *game)
{
	int	w;
	int	h;

	game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/door.xpm", &w, &h);
	game->image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/wa.xpm", &w, &h);
	game->image.collectible_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/collectible.xpm", &w, &h);
	game->image.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/pac_semi_left.xpm", &w, &h);
	game->image.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/pac_semi_right.xpm", &w,
			&h);
	game->image.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/pac_semi_down.xpm", &w, &h);
	game->image.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/pac_semi_up.xpm", &w, &h);
	game->image.black_wal = mlx_xpm_file_to_image(game->mlx_ptr,
			"/Users/apple/Desktop/so_long/textures1/black_wal.xpm", &w, &h);
	if (ft_check(&game->image) == -1)
		ft_free(game);
}
