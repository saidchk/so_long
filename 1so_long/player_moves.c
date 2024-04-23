#include "so_long.h"


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
	if (game->map[game->y][game->x] == 'p' && game->map[game->y - 1][game->x] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
				game->map[game->y][game->x] = '0';
				game->map[game->y - 1][game->x] = 'p';
				game->number_moves++;
				game->y--;
				put_number(game->number_moves);
				write (1, "\n", 1);
	}
}
void move_down(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y + 1][game->x] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
				game->map[game->y][game->x] = '0';
				game->map[game->y + 1][game->x] = 'p';
				game->number_moves++;
				game->y++;
				put_number(game->number_moves);
				write (1, "\n", 1);
	}
}
void move_left(s_data *game)
{
	if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x - 1] == '1')
				return ;
	else if (game->map[game->y][game->x] == 'p')
	{
				game->map[game->y][game->x] = '0';
				game->map[game->y][game->x - 1] = 'p';
				game->number_moves++;
				game->x--;
				put_number(game->number_moves);
				write (1, "\n", 1);
	}
}
void move_right(s_data *game)
{
	
		
			if (game->map[game->y][game->x] == 'p' && game->map[game->y][game->x + 1] == '1')
				return ;
			else if (game->map[game->y][game->x] == 'p')
			{
				game->map[game->y][game->x] = '0';
				game->map[game->y][game->x + 1] = 'p';
				game->number_moves++;
				game->x++;
				put_number(game->number_moves);
				write (1, "\n", 1);
			}

}
