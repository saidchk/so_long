#include "so_long.h"

char *get_next_line(int fd)
{
    char    tab[20000];
    char    c[1];
    int     i;

    i = 0;
    read(fd, c,1);
    while (read(fd, tab, 1) )
    {
        
    }
}