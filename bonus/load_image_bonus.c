/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:41:54 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int ft_check(s_img_adrr *ptr)
{
    if (!ptr->black_wal || !ptr->collectible_ptr || !ptr->ennemi_ptr || !ptr->exit || !ptr->pac_down || !ptr->pac_left || !ptr->pac_right || !ptr->pac_semi_down || !ptr->pac_semi_left || !ptr->pac_semi_right || !ptr->pac_semi_up || !ptr->pac_up || !ptr->player_ptr || !ptr->wall_ptr || !ptr->pac_semi || !ptr->pac_tr || !ptr->pac_min_tr)
    {
        write (1, "error in loading image\n", 24);
        return(-1);
    }
    return (1);
}
void	ft_load_image(s_data *game)
{
	int	w;
	int	h;

	game->image.pac_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_open_up.xpm", &w, &h);
	game->image.pac_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_open_left.xpm", &w, &h);
	game->image.pac_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_open_right.xpm", &w, &h);
	game->image.pac_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_open_down.xpm", &w, &h);
	game->image.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_semi_left.xpm", &w, &h);
	game->image.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_semi_right.xpm", &w, &h);
	game->image.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_semi_down.xpm", &w, &h);
	game->image.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_semi_up.xpm", &w, &h);
	game->image.player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/pac_closed.xpm", &w, &h);
	game->image.black_wal = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures1/black_wal.xpm", &w, &h);
  if (ft_check(&game->image) == -1)
        ft_free(game, game->map_len);
}
