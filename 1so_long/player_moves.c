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
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j =0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'p' && game->map[i - 1][j] == '1')
				return ;
			else if (game->map[i][j] == 'p' && game->map[i - 1][j] != '1')
			{
				game->map[i][j] = '0';
				game->map[i - 1][j] = 'p';
				game->number_moves++;
				put_number(game->number_moves);
				write (1, "\n", 1);
				return;
			}

			j++;
		}
		i++;
	}
}
void move_down(s_data *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j =0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'p' && game->map[i + 1][j] == '1')
				return ;
			else if (game->map[i][j] == 'p' && game->map[i + 1][j] != '1')
			{
				game->map[i][j] = '0';
				game->map[i + 1][j] = 'p';
				game->number_moves++;
				put_number(game->number_moves);
				write (1, "\n", 1);
				return;
			}

			j++;
		}
		i++;
	}
}
void move_left(s_data *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j =0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'p' && game->map[i][j - 1] == '1')
				return ;
			else if (game->map[i][j] == 'p' && game->map[i][j - 1] != '1')
			{
				game->map[i][j] = '0';
				game->map[i][j - 1] = 'p';
				game->number_moves++;
				put_number(game->number_moves);
				write (1, "\n", 1);
				return;
			}

			j++;
		}
		i++;
	}
}
void move_right(s_data *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j =0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'p' && game->map[i][j + 1] == '1')
				return ;
			else if (game->map[i][j] == 'p' && game->map[i][j + 1] != '1')
			{
				game->map[i][j] = '0';
				game->map[i][j + 1] = 'p';
				game->number_moves++;
				put_number(game->number_moves);
				write (1, "\n", 1);
				return;
			}

			j++;
		}
		i++;
	}
}
