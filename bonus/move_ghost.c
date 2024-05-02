 #include "minilibx/mlx.h"
 #include <math.h>
 #include "so_long.h"
 #include <stdio.h>

// if (game->map[game->ennemi.y_g ][game->ennemi.x_g] == '.')
// 	{
// 		printf("u-------%c--%i--\n",game->map[game->ennemi.y_g][game->ennemi.x_g] ,game->map[game->ennemi.y_g][game->ennemi.x_g]);
// 		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
// 			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
// 		if (game->map[game->ennemi.y_g ][game->x_exit] != 't')
// 			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
// 				game->image.collectible_ptr, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
// 		check = 0;
// 	}
// 	else
// 	{
// 		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
// 			game->image.black_wal, (game->ennemi.x_g) * 37, game->ennemi.y_g * 37);
// 	}


// void check_walls(s_data *game)
// {
// 	int x = game->ennemi.x_g;
// 	int y = game->ennemi.y_g;

// 	char v = 'v';
// 	char h = 'h';

// 	game->d = 'g';

// 	// 	if (game->x == game->ennemi.x_g && game->map[y+1][x] == '1' && game->map[y-1][x] == '1')
// 	// {
// 	// 	if (game->ennemi.x_g-1 < game->x)
// 	// 		while (game->map[y + 1][game->ennemi.x_g] == '1' && game->map[y-1][game->ennemi.x_g + 1] == '1')
// 	// 		move_right_ennemi(game);
// 	// 	else
// 	// 		while (game->map[y + 1][game->ennemi.x_g] == '1' && game->map[y-1][game->ennemi.x_g + 1] == '1')
// 	// 			move_left_ennemi(game);
// 	// 	return;
// 	// }
// 	if (game->y == game->ennemi.y_g && game->map[y][x + 1] == '1' && game->map[y][x -1 ] == '1')
// 	{
// 		if (game->ennemi.y_g-1 < game->ennemi.y_g)
// 			game->d = 'd';
// 		else
// 			game->d = 'u';
// 		return;
// 	}
// 	if ( game->map[y][x-1] == '1')
// 	{
	
// 					printf("--d---\n");

// 		while (game->map[game->ennemi.y_g][x -1] == '1' && game->map[game->ennemi.y_g-1][x] != '1')
// 			move_up_ennemi(game);
// 		while (game->map[game->ennemi.y_g][x-1] == '1' && game->map[game->ennemi.y_g+1][x] != '1')
// 			move_down_ennemi(game);
// 		if (game->map[game->ennemi.y_g][x -1] != '1')
// 			game->d = 'l';
// 	}
// 	 if (game->d== 'g' &&  game->map[y][x + 1] == '1')
// 	{
// 			printf("--6---\n");
// 			while (game->map[game->ennemi.y_g][x +1] == '1' && game->map[game->ennemi.y_g-1][x] != '1')
// 			move_up_ennemi(game);
// 		while (game->map[game->ennemi.y_g][x+1] == '1' && game->map[game->ennemi.y_g+1][x] != '1')
// 			move_down_ennemi(game);
// 		if (game->map[game->ennemi.y_g][x +1] != '1')
// 			game->d = 'r';
// 	}
// 	 if (game->d== 'g' && game->map[y - 1][x] == '1')
// 	{
// 			printf("--u---\n");

// 		while (game->map[y - 1][game->ennemi.x_g] == '1' && game->map[y][game->ennemi.x_g - 1] != '1')
// 			move_left_ennemi(game);
// 		while (game->map[y - 1][game->ennemi.x_g] == '1' && game->map[y][game->ennemi.x_g + 1] != '1')
// 			move_right_ennemi(game);
// 		if (game->map[y-1][game->ennemi.x_g] != '1')
// 			game->d = 'u';
// 	}
// 	 if ( game->d== 'g' && game->map[y + 1][x] == '1')
// 	{
// 					printf("--7---\n");

// 		while (game->map[y + 1][game->ennemi.x_g] == '1' && game->map[y][game->ennemi.x_g + 1] != '1')
// 			move_right_ennemi(game);
// 		while (game->map[y + 1][game->ennemi.x_g] == '1' && game->map[y][game->ennemi.x_g - 1] != '1')
// 			move_left_ennemi(game);
// 		if (game->map[y+1][game->ennemi.x_g] != '1')
// 			game->d = 'd';
// 	}

	
// 	// while (game->ennemi.x_g == x )
// 	// 	if (game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
// 	// 	 	move_right_ennemi(game);
// 	// 	if (game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1')
// 	// 		move_left_ennemi(game);
// 	// 	else if ( game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1')
// 	// 		move_up_ennemi(game);
// 	// 	else
// 	// 		move_down_ennemi(game);
// 	// 	if (game->check == 0)
// 	// 		game->check = 1;
// 	// 	else 
// 	// 		game->
	
// }
// void  move(s_data *game)
// {
// 	game->check = 1;

// // 	printf("P1-----(%i, %i)=-----\n",game->x, game->y);
// //    printf("B1-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);
   
// 	printf("--%c---\n", game->d);

//      if (game->d != 'd' && game->d != 'l' &&game->d != 'r' && (game->ennemi.y_g > game->y || game->d == 'u') && game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1')
// 	 {
// 		printf("--1---\n");
// 		game->d = 'g';
//         move_up_ennemi(game);
// 	 }
//     else if (game->d != 'l' &&game->d != 'r'  && game->d != 'u'&& (game->ennemi.y_g < game->y ||  game->d == 'd')&& game->map[game->ennemi.y_g + 1][game->ennemi.x_g] != '1')
//     {
// 		printf("--2---\n");
// 		game->d = 'g';
// 		   move_down_ennemi(game);
// 	}
// 	//  else if (game->check)
// 	// // /{
// 	// 	/ 	check_walls(game);
	


//    else if (game->d != 'r'&& game->d != 'u' && game->d != 'd' && (game->ennemi.x_g > game->x || game->d == 'l')&& game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1' )
//      {
// 				printf("--3---\n");

// 		game->d = 'g';
// 		   move_left_ennemi(game);
// 	}
//     else if (game->d != 'l' && game->d != 'u' && game->d != 'd' && (game->ennemi.x_g < game->x   || game->d == 'r')&& game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
//      {
// 				printf("--4---\n");

// 		game->d = 'g';
// 		  move_right_ennemi(game);
// 		}
//      else 
// 	 {
// 				printf("--5---\n");

// 	 check_walls(game);
// 	 }
// 	//printf("A1-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);
//     // {
//     //     if (game->ennemi.x_g > game->x && game->ennemi.y_g > game->y && game->map[game->ennemi.y_g - 1][game->ennemi.x_g] != '1' )
//     //         move_up_ennemi(game);
//     //     else if ( game->map[game->ennemi.y_g + 1][game->ennemi.x_g] != '1')
//     //     	move_down_ennemi(game);
// 	// 	else if ( game->map[game->ennemi.y_g][game->ennemi.x_g - 1] != '1')
//     //     move_left_ennemi(game);
//     // 	else if ( game->map[game->ennemi.y_g][game->ennemi.x_g + 1] != '1')
//     //    	move_right_ennemi(game);
//     // }
// 	//printf("A2-----(%i, %i)=-----\n",game->ennemi.x_g, game->ennemi.y_g);

// }


void Previous_move(s_data *game)
{
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
	if (u != 10000 &&u <= d && u <= r && u <= l )
	{
		move_up_ennemi(game);
		game->d = 'u';
	}
	else if (l != 10000 &&l <= d && l <= u && l <= r)
	{
		move_left_ennemi(game);
		game->d = 'l';
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
	dis[1] =10000;
	dis[2] = 10000;
	dis[3]= 10000;
	if (game->map[e_y - 1][e_x] != '1' && game->d != 'd')
		dis[0] = abs(e_x - game->x) + abs(e_y - 1 - game->y);
	if (game->map[e_y + 1][e_x] != '1' && game->d != 'u')
		dis[1] = abs(e_x - game->x) + abs(e_y + 1 - game->y);
	if (game->map[e_y][e_x + 1] != '1' && game->d != 'l')
		dis[2] = abs(e_x + 1 - game->x) + abs(e_y - game->y);
	if (game->map[e_y][e_x - 1] != '1' && game->d != 'r')
		dis[3] = abs(e_x - 1 - game->x) + abs(e_y  - game->y);
	move_ennemi(game, dis[0], dis[1], dis[2], dis[3]);
}
