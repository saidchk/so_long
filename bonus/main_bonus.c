/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 16:44:40 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int keycode, void *param)
{
	t_data	*game;

	game = (t_data *)(param);
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
		game->keycode = keycode;
	if (keycode == 53)
	{
		ft_free(game, game->map_len);
	}
	return (0);
}

void	put_door(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.exit,
		game->x_exit * 37, game->y_exit * 37);
	game->counter_of_food--;
}

void	direction(t_data *game)
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
}

int	animation(t_data *game)
{
	static int	i = 0;
	static int	j = 0;

	if (game->counter_of_food == 0)
		put_door(game);
	i++;
	if (i == 2500)
	{
		direction(game);
		i = 0;
	}
	else if (i == 450)
		put_pacman(game, game->keycode);
	else if (i == 1300)
		ft_i(game, game->keycode);
	else if (i == 2000)
		put_pacman(game, game->keycode);
	if (j++ == 2600 && game->ennemi.x_g != -1)
	{
		move(game);
		j = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (write(1, "please enter 1 arg\n", 19), 0);
	set_null(&game.image);
	game.keycode = 15645;
	game.mlx_ptr = NULL;
	game.window_ptr = NULL;
	game.number_moves = 0;
	check_map(av[1], &game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (write(1, "error\n", 6), ft_free(&game, game.map_len), 1);
	game.window_ptr = mlx_new_window(game.mlx_ptr, game.weight_map * 37,
			game.map_len * 37, "so_long");
	if (!game.window_ptr)
		return (write(1, "error\n", 6), ft_free(&game, game.map_len), 1);
	ft_add_img(&game);
	mlx_hook(game.window_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window_ptr, 17, (0L), ft_close, &game);
	mlx_loop_hook(game.mlx_ptr, animation, &game);
	mlx_loop(game.mlx_ptr);
}
