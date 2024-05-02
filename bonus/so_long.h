#ifndef SO_LONG
# define SO_LONG

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//---------struct for load img----------//
typedef struct img_addr
{
	void	*ennemi_ptr;
	void	*pac_tr;
	void	*pac_min_tr;
	void	*player_ptr;
	void	*pac_left;
	void	*pac_right;
	void	*pac_semi;
	void	*pac_up;
	void	*pac_down; 
	void	*pac_semi_left;
	void	*pac_semi_right;
	void	*pac_semi_up;
	void	*pac_semi_down; 
	void	*wall_ptr;
	void	*black_wal;
	void	*collectible_ptr;
	void	*exit;

}s_img_adrr;

typedef struct 
{
	int number_of_c ;
    int number_of_p ;
    int number_of_e;
	int x;
    int y;
}num_of_composed;

typedef struct
{
	int x_g;
	int y_g;
}move_ghost;

typedef struct data
{
    void		*mlx_ptr;
    void		*window_ptr;
    char		**map;    
    int			map_len;
	int			weight_map;
	int			number_moves;
	int			x;
	int			y;
	int			keycode;
	s_img_adrr	image;
	int			counter_of_food;
	int			x_exit;
	int			y_exit;
	move_ghost	ennemi;
	int			check;
	char		d;
	int			size_m;
}s_data;


void get_next_line(int fd, s_data *game);
void put_pacman(s_data *game, int keycode);
void ft_add_img(s_data *game);
void get_map(s_data *game, char *map_name);
void put_image(s_data *game);
void move_up(s_data *game);
void move_down(s_data *game);
void move_right(s_data *game);
void move_left(s_data *game);
void check_map(char *file_name, s_data *game);
void ft_free(s_data *game);
void ft_i(s_data *game, int keycode);
void remove_traces(s_data *game, int keycode);
void end_animation(s_data *game);
void  move(s_data *game);
void move_right_ennemi(s_data *game);
void move_left_ennemi(s_data *game);
void move_up_ennemi(s_data *game);
void move_down_ennemi(s_data *game);
void ft_load_image(s_data *game);

#endif