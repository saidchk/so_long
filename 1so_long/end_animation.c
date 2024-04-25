#include "so_long.h"
#include "minilibx/mlx.h"

int ft_wait(s_data *game)
{
    static int i = 0;

    if (i > 3000)
      ft_free(game);
    if (i == 500)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.player_ptr, game->x * 37, game->y * 37);
    }
    else if (i == 1000)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_up, game->x * 37, game->y * 37);
    }
    if (i == 1500)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi, game->x * 37, game->y * 37);
    }
    else if (i == 2000)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
         mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_down, game->x * 37, game->y * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_down, game->x * 37, game->y * 37);
    }
    else if (i == 2500)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_down, game->x * 37, game->y * 37);
    }
    else if (i == 3000)
    {
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
		game->image.black_wal, game->x * 37, (game->y) * 37);
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.pac_semi_down, game->x * 37, game->y * 37);
    }
    i++;
    return(0);
}
void stop()
{
    int i = 0;
    while (i < 2000000000)
        i++;
}
void end_animation(s_data *game)
{
   
    mlx_loop_hook(game->mlx_ptr, ft_wait, game);
    mlx_loop(game->mlx_ptr);
   
    
}
