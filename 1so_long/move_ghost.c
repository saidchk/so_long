 #include "minilibx/mlx.h"
 #include "so_long.h"

static int check = 0;
void move_up_ennemi(s_data *game)
{
	
	if (check == 1)
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
	if (game->map[game->ennemi.y_g - 1][game->x_exit] == '.')
		check = 1;
	game->ennemi.y_g--;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->check = 0;
}
void move_down_ennemi(s_data *game)
{
	if (check == 1)
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
	if (game->map[game->ennemi.y_g + 1][game->ennemi.x_g] == '.')
		check = 1;
	game->ennemi.y_g++;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->check = 0;
}
void move_left_ennemi(s_data *game)
{
	if (check == 1)
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
	if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] == '.')
		check = 1;
	game->ennemi.x_g--;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->check = 0;
}
void move_right_ennemi(s_data *game)
{
	
	if (check == 1)
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
	if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] == '.')
		check = 1;
	game->ennemi.x_g++;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
			game->image.ennemi_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
	game->check = 0;
}

void  move(s_data *game)
{
	static int check = 1;

	//printf("P1-----(%i, %i)=-----\n",game->x, game->y);
   //printf("B1-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);
   
	if (game->ennemi.y_g == game->y || game->ennemi.x_g == game->x && )
	{
		if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
		 	move_right_ennemi(game);
		else if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1')
			move_left_ennemi(game);
		else if ( game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1')
			move_up_ennemi(game);
		else
			move_down_ennemi(game);
	}
     else if (game->ennemi.y_g > game->y && game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1')
        move_up_ennemi(game);
    else if (game->ennemi.y_g < game->y && game->map[game->ennemi.y_g + 1][game->ennemi.x_g] != '1')
        move_down_ennemi(game);

	//printf("A1-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);
    if (game->ennemi.x_g > game->x && game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1')
        move_left_ennemi(game);
    else if (game->ennemi.x_g < game->x && game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
       move_right_ennemi(game);
    // else if (game->check)
    // {
    //     if (game->ennemi.x_g > game->x && game->ennemi.y_g > game->y && game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1' )
    //         move_up_ennemi(game);
    //     else if ( game->map[game->ennemi.y_g + 1][game->ennemi.x_g] != '1')
    //     	move_down_ennemi(game);
	// 	else if ( game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1')
    //     move_left_ennemi(game);
    // 	else if ( game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
    //    	move_right_ennemi(game);
    // }
	//printf("A2-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);

}
