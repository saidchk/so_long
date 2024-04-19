#include "mlx/mlx.h"
#include "so_long.h"

ft_add_img(s_data *game)
{
    int w;
    int h;
    s_img_adrr image;

    image.player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_left.xpm",&w,&h);
    image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"wall.xpm",&w,&h);
    image.ennemi_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"ghost_down2.xpm",&w,&h);
    
}