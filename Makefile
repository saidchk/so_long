CC = cc
FLAGS = -Wall -Wextra -Werror
lib = -L minilibx
FRAMEWORKSFLAGS =   -lmlx -framework OpenGL -framework AppKit
src = main.c\
directions_of_ghost.c\
end_animation.c\
free_map.c\
ft_add_img.c\
get_map.c\
get_next_line.c\
load_image.c\
move_ghost.c\
player_moves.c\
check_map.c

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
			bonus/check_map_bonus.c

fsa= -fsanitize=address 
NAME = so_long
BONUS_NAME = so_long_bonus
OBJ = $(src:.c=.o)
OBJ_BONUS := $(src_bonus:.c=.o) 


all : $(NAME)

${NAME} : ${OBJ} so_long.h
	${CC} ${FLAGS} ${OBJ} ${lib} ${FRAMEWORKSFLAGS} -o $@

%.o : %.c
	$(CC) ${FLAGS} -c $<

bonus: ${BONUS_NAME} 

$(BONUS_NAME) : $(OBJ_BONUS) bonus/so_long_bonus.h
	${CC} ${FLAGS} $(OBJ_BONUS) ${lib} ${FRAMEWORKSFLAGS} -o $@ 

%.o: %.c
	${CC}  ${FLAGS} -c $< -o $@

clean: 
	rm $(OBJ_BONUS)

fclean: clean
	rm ${BONUS_NAME}

re : fclean bonus



