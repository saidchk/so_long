#include "so_long.h"
#include "minilibx/mlx.h"


void ft_put(s_data *game, void *pac)
{
   mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, game->x * 37, game->y * 37);
  mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			pac, game->x * 37, game->y * 37);
}
int ft_wait(s_data *game)
{
    static int i = 0;

    if (i > 3000)
      ft_free(game);
    if (i == 500)
			ft_put (game,game->image.player_ptr);
    
    else if (i == 800)
    ft_put (game, game->image.pac_semi_up);
  
    if (i == 1600)
        ft_put (game, game->image.pac_semi);
    
    else if (i == 2400)
        ft_put (game, game->image.pac_tr);

    else if (i == 2900)
        ft_put (game, game->image.pac_min_tr);

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
