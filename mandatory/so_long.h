/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 22:47:11 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//---------struct for load img----------//
typedef struct img_addr
{
	void				*ennemi_ptr;
	void				*pac_tr;
	void				*pac_min_tr;
	void				*player_ptr;
	void				*pac_left;
	void				*pac_right;
	void				*pac_semi;
	void				*pac_up;
	void				*pac_down;
	void				*pac_semi_left;
	void				*pac_semi_right;
	void				*pac_semi_up;
	void				*pac_semi_down;
	void				*wall_ptr;
	void				*black_wal;
	void				*collectible_ptr;
	void				*exit;

}						t_img_adrr;

typedef struct num
{
	int					number_of_c;
	int					number_of_p;
	int					number_of_e;
}						t_num_of_composed;

typedef struct move
{
	int					x_g;
	int					y_g;
}						t_move_ghost;

typedef struct data
{
	void				*mlx_ptr;
	void				*window_ptr;
	char				**map;
	int					map_len;
	int					weight_map;
	int					number_moves;
	int					x;
	int					y;
	int					keycode;
	t_img_adrr			image;
	int					counter_of_food;
	int					x_exit;
	int					y_exit;
	int					size_m;
	t_num_of_composed	counter;
}						t_data;

void					put_door(t_data *game);
void					get_next_line(int fd, t_data *game);
void					put_pacman(t_data *game);
void					ft_add_img(t_data *game);
void					get_map(t_data *game, char *map_name);
void					put_image(t_data *game);
void					move_up(t_data *game);
void					move_down(t_data *game);
void					move_right(t_data *game);
void					move_left(t_data *game);
void					check_map(char *file_name, t_data *game);
void					ft_free(t_data *game);
void					remove_traces(t_data *game, int keycode);
void					ft_load_image(t_data *game);
int						ft_close(t_data *game);

#endif