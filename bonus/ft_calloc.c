
#include "so_long_bonus.h"

void *ft_calloc(size_t n, size_t size)
{
    void    *res;
    int     i;
    char    *str;

    i = 0;
    res = malloc(n * size);
    if (res == NULL)
        return(NULL);
    str = (char *)(res);
    while (i < size * n)
    {
        str[i] = 0;
        i++;
    }
    return(res);
}