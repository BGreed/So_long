/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:42:20 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 17:13:53 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

void    flood_fill(char **map, int x, int y, int *c, int *e)
{
    if (x < 0 || y < 0 || map[y][x] == '\0' || map[y][x] == '1' || map[y][x] == 'V')
        return ;
    if (map[y][x] == 'C')
        (*c)++;
    if (map[y][x] == 'E')
    {
        (*e)++;
        return ;
    }
    map[y][x] = 'V';
    flood_fill(map, x + 1, y, c, e);
    flood_fill(map, x - 1, y, c, e);
    flood_fill(map, x, y + 1, c, e);
    flood_fill(map, x, y - 1, c, e);
}

int ft_check_accessible(t_data *data)
{
    char **map_copy;
    int count_c;
    int count_e;

    count_c = 0;
    count_e = 0;
    map_copy = ft_map_copy(data->maps);
    if (!map_copy)
        return (ft_putendl_fd("Error\nMalloc Failed", 2), EXIT_FAILURE);
    if (!ft_find_player(data->maps, &data->px, &data->py))
        return (ft_free_map(map_copy),
                ft_putendl_fd("Error\nPlayer Not Found", 2), EXIT_FAILURE);
    flood_fill(map_copy, data->px, data->py, &count_c, &count_e);
    if (count_c < ft_count_char(data->maps, 'C')
        || count_e < ft_count_char(data->maps, 'E'))
        return (ft_free_map(map_copy),
                ft_putendl_fd("Error\nUnreachable Items", 2), EXIT_FAILURE);
    return (ft_free_map(map_copy), EXIT_SUCCESS);
}


int ft_count_char(char **map, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j++] == c)
                count++;
        }
        i++;
    }
    return (count);
}

char    **ft_map_copy(char **map)
{
    int     i;
    int     len;
    char    **copy;

    len = 0;
    while (map[len])
        len++;
    copy = (char **)malloc(sizeof(char *) * (len + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            ft_free_map(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

int ft_find_player(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = j;
                *y = i;
                return (1);
            }
            j++;
        }
        i++;
    }
    *x = -1;
    *y = -1;
    return (0);
}

