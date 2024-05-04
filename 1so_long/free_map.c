#include "so_long.h"
#include "minilibx/mlx.h"

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
    if (game->mlx_ptr != NULL && game->window_ptr != NULL)
        mlx_destroy_window(game->mlx_ptr, game->window_ptr);
    exit(1);
}
