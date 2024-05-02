#include "so_long.h"
#include "minilibx/mlx.h"

void move_up_ennemi(s_data *game)
{
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == 'P' || game->map[game->ennemi.y_g-1][game->ennemi.x_g] == 'P')
	{
		if (game->map[game->ennemi.y_g - 1][game->ennemi.x_g] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g) * 37);
		end_animation(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g - 1) * 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);	
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->ennemi.y_g--;
}
void move_down_ennemi(s_data *game)
{
	if (game->map[game->ennemi.y_g+1][game->ennemi.x_g] == 'P' || game->map[game->ennemi.y_g ][game->ennemi.x_g] == 'P')
	{
		if (game->map[game->ennemi.y_g + 1][game->ennemi.x_g] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g) * 37);
		end_animation(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, (game->ennemi.y_g+1) * 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->ennemi.y_g++;
}
void move_left_ennemi(s_data *game)
{	
	if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] == 'P' || game->map[game->ennemi.y_g][game->ennemi.x_g ] == 'P')
	{
		 if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g) * 37);
		end_animation(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g - 1) * 37, game->ennemi.y_g * 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);	
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->ennemi.x_g--;
}
void move_right_ennemi(s_data *game)
{
	if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] == 'P' || game->map[game->ennemi.y_g][game->ennemi.x_g] == 'P')
	{
		if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		else
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
				game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g) * 37);
		end_animation(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g+1) * 37, game->ennemi.y_g * 37);
	if (game->map[game->ennemi.y_g][game->ennemi.x_g] == '.')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);	
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->ennemi.x_g++;
}