/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/07 16:40:50 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_door(t_data *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->image.exit,
		game->x_exit * 37, game->y_exit * 37);
}

int	key_press(int keycode, void *param)
{
	t_data	*game;

	game = (t_data *)(param);
	if (keycode == 13 || keycode == 126 || keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123 || keycode == 2 || keycode == 124)
		game->keycode = keycode;
	if (keycode == 53)
		ft_free(game, game->map_len);
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	put_pacman(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (write(1, "please enter 1 arg\n", 19), 0);
	set_null(&game.image);
	game.mlx_ptr = NULL;
	game.window_ptr = NULL;
	game.number_moves = 0;
	check_map(av[1], &game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (write(1, "error in allocation\n", 21),
		 ft_free(&game, game.map_len), 0);
	game.window_ptr = mlx_new_window(game.mlx_ptr, game.weight_map * 37,
			game.map_len * 37, "so_long");
	if (!game.window_ptr)
	return (write(1, "error in allocation\n", 21),
	 ft_free(&game, game.map_len), 0);
	ft_ran_img(&game);
	mlx_hook(game.window_ptr, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window_ptr, 17, (0L), ft_close, &game);
	mlx_loop(game.mlx_ptr);
}
