#ifndef SO_LONG
#define SO_LONG

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//---------struct for load img----------//
typedef struct img_addr
{
	void	*ennemi_ptr;
	void	*player_ptr; 
	void	*wall_ptr;
	void	*collectible_ptr;
	void	*exitr_otr;

}s_img_adrr;

typedef struct 
{
	int number_of_collectibles ;
    int number_of_players ;
    int number_of_exit;
	int x;
    int y;
}num_of_composed;

typedef struct data
{
    void    *mlx_ptr;
    void    *window_ptr;
    char    **map;    
    int     map_len;
	int		weight_map;
	int		number_moves;
}s_data;

// /* Color codes for printf  */
// # define DEFAULT "\033[0;39m"
// # define GRAY "\033[0;90m"
// # define RED "\033[0;91m"
// # define GREEN "\033[0;92m"
// # define YELLOW "\033[0;93m"
// # define BLUE "\033[0;94m"
// # define MAGENTA "\033[0;95m"
// # define CYAN "\033[0;96m"
// # define WHITE "\033[0;97m"

void get_next_line(int fd, s_data *game);
void ft_add_img(s_data *game);
void get_map(s_data *game);
void put_image(s_data *game, int keycode);
void move_up(s_data *game);
void move_down(s_data *game);
void move_right(s_data *game);
void move_left(s_data *game);
void check_map(char *file_name, s_data *game);
void ft_free(s_data *game);

#endif