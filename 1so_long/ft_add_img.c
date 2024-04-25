#include "minilibx/mlx.h"
#include "so_long.h"

void remove_traces(s_data *game, int keycode)
{
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, game->x  * 37, (game->y )* 37);

    if ((keycode == 0 || keycode == 123) && game->map[game->y][game->x + 1] != '.' && game->map[game->y][game->x + 1] != '1')
    {
            mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, (game->x + 1) * 37, game->y * 37);
    }    
    else if ((keycode == 2 || keycode == 124) && game->map[game->y][game->x - 1] != '.' && game->map[game->y][game->x - 1] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, (game->x - 1) * 37, game->y * 37);
    }
    else if ((keycode == 13 || keycode == 126 ) && game->map[game->y + 1][game->x] != '.' && game->map[game->y + 1][game->x] != '1')
    {
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, game->x  * 37, (game->y + 1)* 37);
    }
    else if ((keycode == 1 || keycode == 125) && game->map[game->y - 1][game->x] != '.' && game->map[game->y - 1][game->x] != '1')
    {
         mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, game->x  * 37, (game->y - 1)* 37);
    }

}

void ft_i(s_data *game, int keycode)
{
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, game->x  * 37, (game->y )* 37);
    if ((keycode == 0 || keycode == 123) )
    {
            mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_left, game->x * 37, game->y * 37);

    }
    else if ((keycode == 2 || keycode == 124) )
    {
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_right, game->x * 37, game->y * 37) ;
    }
    else if ((keycode == 13 || keycode == 126 ))
    {
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_up, game->x * 37, game->y * 37); 
    }
    else if ((keycode == 1 || keycode == 125) )
    {
         mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_down, game->x * 37, game->y * 37);
    }
}

void put_pacman(s_data *game, int keycode)
{
    
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.black_wal, game->x  * 37, (game->y )* 37);
    if (keycode == 0 || keycode == 123)
       mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_semi_left, game->x * 37, game->y * 37);
    else if (keycode == 2 || keycode == 124)    
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_semi_right, game->x * 37, game->y * 37) ;
    else if(keycode == 13 || keycode == 126 )
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_semi_up, game->x * 37, game->y * 37); 
	else if (keycode == 1 || keycode == 125)
		    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.pac_semi_down, game->x * 37, game->y * 37);
    else if(keycode == 30000)
        mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.player_ptr, game->x * 37, game->y * 37);
    if (game->counter_of_food == 0 && game->x_exit == game->x && game->y_exit == game->y)
    {
        mlx_destroy_window(game->mlx_ptr, game->window_ptr);
        ft_free(game);
        exit(1);
    }
    
}

void put_image(s_data *game)
{

  int i;
  int j;

  i = 0;
  
  while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        { 
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.wall_ptr,j*37,i*37);
            else if (game->map[i][j] == 'p')
                  mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.player_ptr,j*37 ,i*37);
            else if (game->map[i][j] == 'D')
                 mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.ennemi_ptr,j*37 ,i*37);
            else if (game->map[i][j] == '.')
                 mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.collectible_ptr,j*37 ,i*37);
            j++;
        }
        i++;
    }
}

void ft_add_img(s_data *game)
{
    int w;
    int h;

    game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr,"door.xpm",&w,&h);
    game->image.wall_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"wa.xpm",&w,&h);
	game->image.pac_up = mlx_xpm_file_to_image(game->mlx_ptr,"pac_open_up.xpm",&w,&h);
    game->image.pac_left = mlx_xpm_file_to_image(game->mlx_ptr,"pac_open_left.xpm",&w,&h);
    game->image.pac_right = mlx_xpm_file_to_image(game->mlx_ptr,"pac_open_right.xpm",&w,&h);
	game->image.pac_down = mlx_xpm_file_to_image(game->mlx_ptr,"pac_open_down.xpm",&w,&h);
    game->image.pac_semi_left = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_left.xpm",&w,&h);
    game->image.pac_semi_right = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_right.xpm",&w,&h);
	game->image.pac_semi_down = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_down.xpm",&w,&h);
    game->image.pac_semi_up = mlx_xpm_file_to_image(game->mlx_ptr,"pac_semi_up.xpm",&w,&h);
    game->image.player_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"pac_closed.xpm",&w,&h);  
    game->image.black_wal = mlx_xpm_file_to_image(game->mlx_ptr,"black_wal.xpm",&w,&h);
    game->image.ennemi_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"ghost_down2.xpm",&w,&h);
    game->image.collectible_ptr = mlx_xpm_file_to_image(game->mlx_ptr,"collectible.xpm",&w,&h);
    put_image(game);
}
