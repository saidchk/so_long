/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/05 04:25:07 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_close(s_data *game)
{
	ft_free(game);
	return (0);
}
void	ft_free(s_data *game)
{
	free(game->map);
	if (game->mlx_ptr != NULL && game->window_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	
	exit(1);
}
