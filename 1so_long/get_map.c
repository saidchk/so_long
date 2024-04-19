#include "so_long.h"

int count_len(int fd)
{
    char    tab[1];
    int     count;

    count = 0;
    while (read(fd,tab,1) != 0)
    {
        if (tab[0] == '\n')
            count++;
    }
    return(count + 1);
}
void get_map(s_data *game)
{
    int fd;
    int i = 0;
 
    fd = open("map.bar",O_RDONLY);
    game->map_len = count_len(fd);
    close(fd);
    game->map = malloc( sizeof(char *) * (game->map_len + 1));
    if (game->map ==NULL)
        return ;
    game->map[game->map_len] = 0;
    if (!game->map)
    {
        return ;
    }
    fd = open("map.bar",O_RDONLY);
    get_next_line(fd, game);

}

// #include <stdio.h>
// int main()
// {
//     s_data game;
//     int i = 0;
//     int j=0;

//     get_map(&game);
//     while (game.map[i])
//     {
//         printf("%s\n",game.map[i]);
//         i++;
//     }
// }