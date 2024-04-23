#include "so_long.h"

void ft_free(s_data *game)
{
    int i;

    i = 0;
    while (i < game->map_len)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}
