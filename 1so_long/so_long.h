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

typedef struct data
{
    void    *mlx_ptr;
    void    *window_ptr;
    char    **map;    
    int     map_len;
}s_data;

/* Color codes for printf  */
# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

void get_next_line(int fd, s_data *game);
void ft_add_img(s_data *game);
void get_map(s_data *game);
void put_image(s_data *game);


#endif