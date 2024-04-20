#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>


int key_press(int keycode, void *param)
{
	s_data *game;

	game = (s_data *)(param);
	if (keycode == 53)
		mlx_destroy_window(game->mlx_ptr,game->window_ptr);
	else if(keycode == 13 || keycode == 126 )
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);	
	mlx_clear_window(game->mlx_ptr, game->window_ptr);
	put_image(game);

    return (0);
}

int main()
{
	s_data game;

    game.mlx_ptr =  mlx_init();
	if (game.mlx_ptr== NULL)
		return(1);
	game.window_ptr = mlx_new_window(game.mlx_ptr,50*32,40*32,"so_long");
	if (!game.window_ptr)
		return(1);
	ft_add_img(&game);
	//mlx_loop_hook(game.mlx_ptr,put_image , &game);
	mlx_key_hook(game.window_ptr, key_press, &game);
	mlx_loop(game.mlx_ptr);

}
