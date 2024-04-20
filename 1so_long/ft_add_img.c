#include "minilibx/mlx.h"
#include "so_long.h"

void put_image(s_data *game)
{

  int i;
  int j;
  int w;
  int h;
  s_img_adrr image;

    image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"wa.xpm",&w,&h);
    image.player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_left.xpm",&w,&h);
   image.ennemi_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"ghost_down2.xpm",&w,&h);
  i = 0;
      while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        { 
            if (game->map[i][j] == '1')
            {
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.wall_ptr,j*37,i*37);
            }
            else if (game->map[i][j] == 'p')
            {
                  mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.player_ptr,j*37 ,i*37);
               //  mlx_destroy_image(game->mlx_ptr, image.player_ptr);
            }
            else if (game->map[i][j] == 'D')
                 mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.ennemi_ptr,j*37 ,i*37);
            j++;
        }
        i++;
    }
}


void ft_add_img(s_data *game)
{
    int w;
    int h;
    int i;
    int j;

    i =0;
  
    get_map(game);
    put_image(game);
}
