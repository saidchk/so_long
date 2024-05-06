/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 18:10:11 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\n' && str[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*one_line(char *array, int size_line)
{
	char	*row;
	int		i;

	row = malloc(size_line + 1);
	if (row == NULL)
	{
		write(1, "error in allocation\n", 21);
		return (NULL);
	}
	i = 0;
	while (array[i] != '\n' && array[i] != '\0')
	{
		row[i] = array[i];
		i++;
	}
	row[i] = '\0';
	return (row);
}

void	get_next_line(int fd, s_data *game)
{
	char	tab[game->size_m];
	int		size_line;
	char	*head;
	int		size_read;
	int		i;

	i = 0;
	head = tab;
	size_read = read(fd, tab, game->size_m);
	if (size_read <= 0)
		ft_free(game, -1);
	tab[size_read] = 0;
	while (i < game->map_len)
	{
		size_line = ft_strlen(head);
		if (game->weight_map != size_line || game->map_len == size_line)
		{
			write(1, "the map is not rectangular", 26);
			ft_free(game, i -1);
		}
		game->map[i] = one_line(head, size_line);
		if (game->map[i++] == NULL)
			ft_free(game, i-1);
		head += size_line + 1;

	}
}
