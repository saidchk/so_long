/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/05/06 20:26:54 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;
	size_t	i;
	char	*str;

	i = 0;
	res = malloc(n * size);
	if (res == NULL)
		return (NULL);
	str = (char *)(res);
	while (i < size * n)
	{
		str[i] = 0;
		i++;
	}
	return (res);
}
