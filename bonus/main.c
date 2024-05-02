#include "minilibx/mlx.h"
#include "so_long.h"

int	key_press(int keycode, void *param)
{
	s_data	*game;

	game = (s_data *)(param);
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
		game->keycode = keycode;
	if (keycode == 53)
	{
		ft_free(game);
	}
	return (0);
}

void	put_door(s_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.exit,
		game->x_exit * 37, game->y_exit * 37);
	game->counter_of_food--;
}
int	animation(s_data *game)
{
	static int	i = 0;
	static int	j = 0;


	if (game->counter_of_food == 0)
		put_door(game);
	i++;
	j++;
	if (i == 2000)
	{
		if (game->keycode == 13 || game->keycode == 126)
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
	else if (i == 450)
		put_pacman(game, game->keycode);
	else if (i == 900)
		ft_i(game, game->keycode);
	else if (i == 1300)
		put_pacman(game, game->keycode);
	if (j == 2000)
		{
			move(game);
			j = 0;
		}
	return (0);
}

int	ft_close(s_data *game)
{
	ft_free(game);
	return(0);
}

int	main(int ac, char **av)
{
	s_data	game;
	if (ac != 2)
		return (write(1, "please enter 1 arg\n", 19), 0);
	game.keycode = 15645;
	game.mlx_ptr = NULL;
	game.window_ptr = NULL;
	game.number_moves = 0;
	check_map(av[1], &game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (ft_free(&game), 1);
	game.window_ptr = mlx_new_window(game.mlx_ptr, game.weight_map * 37, game.map_len * 37, "so_long");
	if (!game.window_ptr)
	{
		ft_free(&game);
		return (1);
	}
	ft_add_img(&game);
	mlx_hook(game.window_ptr, 3, 1L << 0, key_press, &game);
	mlx_hook(game.window_ptr, 17, (0L), ft_close, &game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_loop(game.mlx_ptr);
}
