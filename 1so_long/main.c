#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void func()
{
	int i = 0;

	while(i < 5000000)
		i++;
}

int animation(s_data *game)
{
	mlx_clear_window(game->mlx_ptr, game->window_ptr);
	put_image(game,30000);
	func();
	return (0);
}
int key_press(int keycode, void *param)
{
	s_data *game;

	game = (s_data *)(param);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr,game->window_ptr);
		ft_free(game);
		exit(EXIT_SUCCESS);
	}
	
	else if(keycode == 13 || keycode == 126 )
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);	
	mlx_clear_window(game->mlx_ptr, game->window_ptr);
	put_image(game,keycode);

    return (0);
}

int main(int ac, char **av)
{
	s_data	game;

	if (ac != 2)
	{
		write(1, "please enter 1 arg" ,18);
		return (0);
	}
	game.number_moves = 0;
	check_map(av[1], &game);
    game.mlx_ptr =  mlx_init();
	if (game.mlx_ptr== NULL)
	{
		ft_free(&game);
		return(1);
	}
	game.window_ptr = mlx_new_window(game.mlx_ptr,50*32,40*32,"so_long");
	if (!game.window_ptr)
	{
		ft_free(&game);
		return(1);
	}
	ft_add_img(&game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_hook(game.window_ptr, 2, 1L<<0, key_press, &game);
	mlx_loop(game.mlx_ptr);

}
