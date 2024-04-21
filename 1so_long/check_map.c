#include "so_long.h"

num_of_composed size;
void    ft_check_extension(char *file_name)
{
    int     i;
    int     j;
    char    *ext = ".ber";

    i = 0; 
    j = 0;
    while (file_name[i]!= '.' && file_name[i])
        i++;
    if (file_name[i] == 0)
    {
        write(1, "Error, the name of file is note valide\n", 39);
            exit(EXIT_FAILURE);
    }

    while(file_name[i])
    {
        if (file_name[i] != ext[j++])
        {
            write(1, "Error, the name of file is note valide\n", 39);
            exit(EXIT_FAILURE);
        }
        i++;
    }    
}
void ft_is_closed(s_data *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map_len)
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] != '1')
                {
                    write (1, "close the map\n", 14);
                    exit(EXIT_FAILURE);
                }

            if (y == 0 || y == game->map_len -1)
                x++;
            else
                break;
        }
        y++;
    }
}
#include <stdio.h>
void check_p_e_c(s_data *game, int *x, int *y)
{

    size.number_of_collectibles = 0;
    size.number_of_players = 0;
    size.number_of_exit = 0;
	size.y = 1;
    while (game->map[size.y])
    {
		size.x = 1;
		 while (game->map[size.y][size.x])
    	{
			if (game->map[size.y][size.x] == 'c')
				size.number_of_collectibles++;
			else if(game->map[size.y][size.x] == 'p')
            {
				size.number_of_players++;
                *x = size.x;
                *y = size.y;
            }
			else if(game->map[size.y][size.x] == 'E')
				size.number_of_exit++;
			size.x++;
    	}
		size.y++;
    }
	if (size.number_of_collectibles < 1 || size.number_of_exit != 1 || size.number_of_players != 1)
			write(1,"error in composed\n",18) ;	
	if (size.number_of_collectibles < 1 || size.number_of_exit != 1 || size.number_of_players != 1)
		 exit(EXIT_FAILURE);	
}

void  flood_fill(char **map ,s_data game,int x, int y, int *count_c)
{
    if ((y < 0 || y >= game.map_len )|| (x < 0 || x >= game.weight_map ) || map[y][x] == 'k')
        return;
    
    if (map[y][x] != 'c' && map[y][x] != 'p' )
    {
        return;
    }
    else
    {
        if (map[y][x] == 'c')
            (*count_c)++;
        map[y][x] = 'k';
        flood_fill(map, game,x + 1, y,count_c);
        flood_fill(map, game,x - 1, y,count_c);
        flood_fill(map, game,x, y + 1, count_c);
        flood_fill(map, game,x, y - 1, count_c);
    }
}
void check_map(char *file_name, s_data *game)
{
    int x;
    int y;
    int count_c;
    char **map;

    count_c = 0;
    ft_check_extension(file_name);
    get_map(game);
    map = game->map;
    ft_is_closed(game);
    check_p_e_c(game, &x, &y);
    flood_fill(map , *game, x, y, &count_c);
    printf("---%s---\n", game->map[1]);
    if (count_c != size.number_of_collectibles)
    {
        write (1, "not valide path\n", 16);
        //mlx_destr
        exit(EXIT_FAILURE);
    }

}
