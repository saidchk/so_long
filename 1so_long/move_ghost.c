#include  "so_long.h"

void flood_fill(s_data *game, int x , int y)
{

}
void move_ghost(s_data *game, int x , int y)
{  
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'D')
            {
                if ( game->map[i + 1][j] == 0)
                {
                    game->map[i][j] = 0;
                    game->map[i + 1][j] = 'D';
                }
                else if ( game->map[i + 1][j] == 0)

            }
        }
    }
    
}
