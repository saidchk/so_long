#ifndef SO_LONG
#define SO_LONG

#include <fcntl.h>
#include <unistd.h>
//---------struct for load img----------//
typedef struct img_addr
{
	void	*player_ptr; 
	void	*wall_ptr;
	void	*ennemi_ptr;
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

#endif