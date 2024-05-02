#include "so_long.h"

int count_len(int fd, int *size)
{
    char    tab[1];
    int     count;

    count = 0;
    *size = 0;
    while (read(fd,tab,1) != 0)
    {
        if (tab[0] == '\n')
        {
            (*size)++;
            count++;
        }
        (*size)++;
    }
    return(count + 1);
}
#include <stdio.h>
void get_map(s_data *game, char *map_name)
{
    int fd;
    int i = 0;
 
    fd = open(map_name,O_RDONLY);
    if (fd == -1)
        printf("dcdj\n");
    game->map_len = count_len(fd, &game->size_m);
    close(fd);
    game->map = malloc( sizeof(char *) * (game->map_len + 1));
    if (game->map ==NULL)
        return ;
    game->map[game->map_len] = 0;
    if (!game->map)
    {
        return ;
    }
    fd = open(map_name, O_RDONLY);
    get_next_line(fd, game);
}
