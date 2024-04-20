#include "so_long.h"

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
			if (game->map[i][j] == 'p' && game->map[i - 1][j] != '1')
			{
				game->map[i][j] = '0';
				game->map[i - 1][j] = 'p';

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
				return;
			}

			j++;
		}
		i++;
	}
}