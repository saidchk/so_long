/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/02 16:47:06 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (size_read == -1)
		free(game);
	game->weight_map = ft_strlen(tab);
	tab[size_read] = 0;
	while (i < game->map_len)
	{
		size_line = ft_strlen(head);
		if (game->weight_map != size_line || game->map_len == size_line)
		{
			write(1, "the map is not rectangular", 26);
			ft_free(game);
		}
		game->map[i] = one_line(head, size_line);
		head += size_line + 1;
		i++;
	}
}
