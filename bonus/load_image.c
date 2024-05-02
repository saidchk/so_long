/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/02 21:42:08 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int ft_check(s_img_adrr *ptr)
{
    if (!ptr->black_wal || !ptr->collectible_ptr || !ptr->ennemi_ptr || !ptr->exit || !ptr->pac_down || !ptr->pac_left || !ptr->pac_right || !ptr->pac_semi_down || !ptr->pac_semi_left || !ptr->pac_semi_right || !ptr->pac_semi_up || !ptr->pac_up || !ptr->player_ptr || !ptr->wall_ptr)
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
        ft_free(game);

}
