 #include "minilibx/mlx.h"
 #include <math.h>
 #include "so_long.h"

//static int check = 0;
void move_up_ennemi(s_data *game)
{
	static int check = 0;

	if (check == 1 && game->d == 'u')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, game->ennemi.x_g * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, game->ennemi.x_g * 37, game->ennemi.y_g * 37);
		check = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	}
	if (game->map[game->ennemi.y_g - 1][game->x_exit] == '.' )
	{
		check = 1;

	}
	game->ennemi.y_g--;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, (game->ennemi.y_g) * 37);
	
}
void move_down_ennemi(s_data *game)
{
	static int check = 0;

	if (check == 1 && game->d == 'd')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		check = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	}
	if (game->map[game->ennemi.y_g + 1][game->ennemi.x_g] == '.' )
	{
		check = 1;

	}
	game->ennemi.y_g++;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, game->ennemi.x_g * 37, (game->ennemi.y_g ) * 37);
}
void move_left_ennemi(s_data *game)
{
	static int check = 0;
	if (check == 1 && game->d == 'l')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		check = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	}
	if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] == '.' )
	{

		check = 1;
	}
	game->ennemi.x_g--;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g ) * 37, game->ennemi.y_g * 37);
}
void move_right_ennemi(s_data *game)
{
	static int check = 0 ;
	if (check == 1 && game->d == 'r')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
		check = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	}
	if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] == '.' )
	{
		check = 1;
	}
	game->ennemi.x_g++;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);

}



int func(char d, char p, char check)
{
	//printf("-----YES---------\n");
	if (check == 'u' && d == 'd' )
		return(0);
	else if (check == 'd' && d == 'u' )
		return (0);
	else if (check == 'r' && d == 'l' )
		return(0);
	else if (check == 'l' && d == 'r' )
		return(0);
	else
	{
		//printf("-----YES---------\n");
		return(1);
	}
}


void Previous_move(s_data *game)
{
	printf("---%c---- \n",game->d );
	if (game->d == 'u')
		move_down_ennemi(game);
	else if(game->d == 'd')
		move_up_ennemi(game);
	else if (game->d == 'l')
		move_right_ennemi(game);
	else
		move_left_ennemi(game);
	game->d = ('d'*(game->d == 'u') + 'u'* (game->d == 'd')+ 'r' * (game->d == 'l') + 'l' * (game->d == 'r'));
}
void move_ennemi(s_data *game ,int u, int d, int r, int l)
{
	static int i = 1;

	printf("move === %i   u===%i  d == %i  l == %d  r====%d \n", i ,u,d,l,r );
	i++;
	//game->d = 'l';
	if (u != 10000 &&u <= d && u <= r && u <= l )
	{
		move_up_ennemi(game);
		game->d = 'u';
	}
	else if (d != 10000 && d <= u && d <= r && d <= l)
	{
		move_down_ennemi(game);
		game->d = 'd';
	}
	else if (r != 10000 && r <= d && r <= u && r <= l)
	{
		move_right_ennemi(game);
		game->d = 'r';
	}
	else if (l != 10000 &&l <= d && l <= u && l <= r)
	{
		move_left_ennemi(game);
		game->d = 'l';
	}
	 else
		Previous_move(game);
	
}
void move(s_data *game)
{
	int dis[4];
	int e_x;
	int e_y;

	e_x = game->ennemi.x_g;
	e_y = game->ennemi.y_g;
	dis[0] =10000;
	dis [1] =10000;
	dis[2] = 10000;
	dis[3]= 10000;
	if (game->map[e_y - 1][e_x] != '1' && func(game->d, game->map[e_y + 1][e_x], 'u'))
		dis[0] = abs(e_x - game->x) + abs(e_y - 1 - game->y);
	if (game->map[e_y + 1][e_x] != '1' && func(game->d, game->map[e_y - 1][e_x], 'd'))
		dis[1] = abs(e_x - game->x) + abs(e_y + 1 - game->y);
	if (game->map[e_y][e_x + 1] != '1' && func(game->d, game->map[e_y][e_x - 1], 'r'))
		dis[2] = abs(e_x + 1 - game->x) + abs(e_y - game->y);
	if (game->map[e_y][e_x - 1] != '1' && func(game->d, game->map[e_y][e_x + 1], 'l'))
		dis[3] = abs(e_x - 1 - game->x) + abs(e_y  - game->y);
	move_ennemi(game, dis[0], dis[1], dis[2], dis[3]);
}
