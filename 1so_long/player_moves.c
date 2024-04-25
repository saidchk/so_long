#include "so_long.h"
#include "minilibx/mlx.h"

void put_number(int num)
{
	char n;

	if (num < 10)
	{
		n = num + 48;
		write (1, &n, 1);
		return;
	}
	else
	{
	put_number(num / 10);
	n = (num % 10) + 48;
	write (1, &n, 1);
	}
}	

void move_up(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y - 1][game->x] == 'D')
		end_animation(game);
	if (game->map[game->y][game->x] == 'p' && game->map[game->y - 1][game->x] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
		if (game->map[game->y - 1][game->x] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'p';
		game->number_moves++;
		game->y--;
		put_number(game->number_moves);
		write (1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}
void move_down(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y + 1][game->x] == 'D')
		end_animation(game);
	if (game->map[game->y][game->x] == 'p' && game->map[game->y + 1][game->x] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
		if (game->map[game->y + 1][game->x] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'p';
		game->number_moves++;
		game->y++;
		put_number(game->number_moves);
		write (1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}
void move_left(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x - 1] == 'D')
		end_animation(game);
	if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x - 1] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
		if (game->map[game->y][game->x - 1] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'p';
		game->number_moves++;
		game->x--;
		put_number(game->number_moves);
		write (1, "\n", 1);
	}
	remove_traces(game, game->keycode);
}
void move_right(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x + 1] == 'D')
	{
		end_animation(game);
		ft_free(game);
	}
	if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x + 1] == '1')
		return ;
	else if (game->map[game->y][game->x] == 'p')
	{
		if (game->map[game->y][game->x + 1] == '.')
			game->counter_of_food--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'p';
		game->number_moves++;
		game->x++;
		put_number(game->number_moves);
		write (1, "\n", 1);
		remove_traces(game, game->keycode);
	}
}
