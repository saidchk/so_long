/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:06:27 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


int	ft_close(s_data *game)
{
	ft_free(game, game->map_len);
	return (0);
}
void	ft_free(s_data *game, int i)
{
	while (i >= 0 )
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
	if (game->mlx_ptr != NULL && game->window_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	
	exit(1);
}
