#include "minilibx/mlx.h"
#include "so_long.h"

void function(s_img_adrr *image, s_data *game, int keycode)
{
    int w;
    int h;
    
    image->wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"wa.xpm",&w,&h);
    if (keycode == 0 || keycode == 123)
        image->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_left.xpm",&w,&h);
    else if (keycode == 2 || keycode == 124)
        image->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_right.xpm",&w,&h);
    else if(keycode == 13 || keycode == 126 )
		image->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_open_up.xpm",&w,&h);
	else if (keycode == 1 || keycode == 125)
		image->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_down.xpm",&w,&h);
    else if(keycode == 30000)
         image->player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_closed.xpm",&w,&h);  

    image->ennemi_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"ghost_down2.xpm",&w,&h);
    image->collectible_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"collectible.xpm",&w,&h);
}

void put_image(s_data *game, int keycode)
{

  static s_img_adrr image;
  int i;
  int j;

  i = 0;
  function(&image, game, keycode);
  while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        { 
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.wall_ptr,j*37,i*37);
            else if (game->map[i][j] == 'p')
                  mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.player_ptr,j*37 ,i*37);
            else if (game->map[i][j] == 'D')
                 mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.ennemi_ptr,j*37 ,i*37);
            else if (game->map[i][j] == '.')
                 mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, image.collectible_ptr,j*37 ,i*37);
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
    int keycode; 

    i =0;
    keycode = 30000;
    put_image(game, keycode);
}
