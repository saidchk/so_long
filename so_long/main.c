#include "mlx/mlx.h"
#include <stdio.h>

void	*ptr_mlx ;


int main()
{
	void	*ptr_window;
	void	*img;
	//char	*player_path = "pac_semi_left.xpm";
	char	*wall_path = "wall.xpm";
	char	*ennemi_path = "ghost_down2.xpm";
	int		img_width;
	int		img_height;

    ptr_mlx =  mlx_init();
	if (ptr_mlx == NULL)
		return(1);
	ptr_window = mlx_new_window(ptr_mlx,1000,1290,"so_long");
	if (!ptr_window)
		return(1);
	ft_add_img(ptr_mlx);
}