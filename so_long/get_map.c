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
//bach ne3raf ch7al fihel fel3ard hit anehtaja f get_next_line,mli nsaredo yehdeb line dik sa3a nehseb ta l3ard 
    fd = open("map.bar",O_RDONLY);
    game->map_len = count_len(fd);
    close(fd);
    game->map = malloc(sizeof(char *) * game->map_len + 1);
    if (!game->map)
        return ;
    fd = open("map.bar",O_RDONLY);
    while (i < game->map_len)
    {
        game->map[i] = get_next_lien(fd);
    }


}

// #include <stdio.h>
// int main()
// {
//     printf("%i",count_len(open("map.bar",O_RDONLY)));
// }