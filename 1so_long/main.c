#include "minilibx/mlx.h"
#include "so_long.h"


int key_press(int keycode, void *param)
{
	s_data *game;
	
	game = (s_data *)(param);
	game->keycode = keycode;
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx_ptr,game->window_ptr);
		ft_free(game);
		exit(1);
	}
	
	// else if(keycode == 13 || keycode == 126)
	// 	move_up(game);
	// else if (keycode == 1 || keycode == 125)
	// 	move_down(game);
	// else if (keycode == 0 || keycode == 123)
	// 	move_left(game);
	// else if (keycode == 2 || keycode == 124)
	// 	move_right(game);	
	// put_pacman(game, keycode);
    return (0);
}


int animation(s_data *game)
{
	static int i = 0;
	//printf("keycode --- %i\n", game->keycode);
	// put_pacman(game,game->keycode);
	//ft_wait();
	//ft_i(game, game->keycode);
	//ft_wait();
	//  put_pacman(game, 30000);
	//  	ft_wait();
	i++;
	if (i == 1600)
	{
	 if(game->keycode == 13 || game->keycode == 126)
		move_up(game);
	else if (game->keycode == 1 || game->keycode == 125)
		move_down(game);
	else if (game->keycode == 0 || game->keycode == 123)
		move_left(game);
	else if (game->keycode == 2 || game->keycode == 124)
		move_right(game);	
	put_pacman(game, 30000);
	i = 0;
	}
	else if (i == 350)
	put_pacman(game, game->keycode);	//ft_wait();
	else if (i == 800)
		ft_i(game, game->keycode);
	else if ( i == 1200)
		put_pacman(game, game->keycode);
	
	return (0);
}

int ft_close (s_data *game)
{
	mlx_destroy_window(game->mlx_ptr,game->window_ptr);
		ft_free(game);
		exit(1);
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
		return(ft_free(&game), 1);
	game.window_ptr = mlx_new_window(game.mlx_ptr,50*32,40*32,"so_long");
	if (!game.window_ptr)
	{
		ft_free(&game);
		return(1);
	}
	ft_add_img(&game);
	mlx_hook(game.window_ptr, 3, 1L<<0, key_press, &game);
	mlx_hook(game.window_ptr, 17, (0L), ft_close, &game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_loop(game.mlx_ptr);
}
