/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakkou <schakkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:38:44 by schakkou          #+#    #+#             */
/*   Updated: 2024/04/20 20:40:20 by schakkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str) {
    int size = 0;
    while (str[size] != '\n' && str[size] != '\0') {
        size++;
    }
    return size;
}

char *one_line(char *array, int size_line) {
    
    char *row = malloc(size_line + 1); 
    if (row == NULL) {
       
        return NULL;
    }
    int i = 0;
    while (array[i] != '\n' && array[i] != '\0') {
        row[i] = array[i];
        i++;
    }
    row[i] = '\0'; 
    return (row);
}

void get_next_line(int fd, s_data *game) {

    
    char *tab;
    char *head;
    int size_line;

    tab = malloc(1000); 
    head = tab;
    if (tab == NULL) {
        // Handle memory allocation failure
        return;
    }
    int size_read = read(fd, tab,1000);
    if (size_read == -1) {
        // Handle read error
        free(tab);
        return;
    }
    tab[size_read] = 0; 
    int i = 0;
    game->weight_map = ft_strlen(tab);
    while (i < game->map_len)
    {
        size_line = ft_strlen(tab);
        if (game->weight_map != size_line || game->map_len == size_line)
        {
            write (1, "the map is not rectangular", 26);
            exit(EXIT_FAILURE);
        }
        game->map[i] = one_line(tab, size_line);
        tab += size_line + 1;
        i++;
    }
    free(head);
}
