CC = cc
FLAGS = -Wall -Wextra -Werror
lib = -L minilibx
FRAMEWORKSFLAGS =   -lmlx -framework OpenGL -framework AppKit
src = mandatory/main.c\
	mandatory/free_map.c\
	mandatory/ft_add_img.c\
	mandatory/get_map.c\
	mandatory/get_next_line.c\
	mandatory/load_image.c\
	mandatory/player_moves.c\
	mandatory/check_map.c

src_bonus = bonus/main_bonus.c\
			bonus/directions_of_ghost_bonus.c\
			bonus/end_animation_bonus.c\
			bonus/free_map_bonus.c\
			bonus/ft_add_img_bonus.c\
			bonus/get_map_bonus.c\
			bonus/get_next_line_bonus.c\
			bonus/load_image_bonus.c\
			bonus/move_ghost_bonus.c\
			bonus/player_moves_bonus.c\
			bonus/check_map_bonus.c\
			bonus/ft_calloc.c

fsa= -fsanitize=address -g
NAME = so_long
BONUS_NAME = so_long_bonus
OBJ = $(src:.c=.o)
OBJ_BONUS = $(src_bonus:.c=.o) 


all : $(NAME)

${NAME} : ${OBJ} mandatory/so_long.h
	${CC} ${FLAGS} ${OBJ} ${FRAMEWORKSFLAGS} -o $@

%.o : %.c
	$(CC) ${FLAGS} -c $< -o $@

bonus: ${BONUS_NAME} 

$(BONUS_NAME) : $(OBJ_BONUS) bonus/so_long_bonus.h
	${CC} ${FLAGS} $(OBJ_BONUS) $(fsa) ${FRAMEWORKSFLAGS} -o $@ 

%.o : %.c
	${CC} ${FLAGS} $(fsa) -c $< -o $@

clean_bonus :
	rm -f $(OBJ_BONUS)

fclean_bonus : clean_bonus
	rm -f ${BONUS_NAME}

re_bonus : fclean bonus

clean: 
	rm -f ${OBJ}

fclean: clean
	rm -f $(NAME) 

re : fclean all