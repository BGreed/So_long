/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:52:23 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 03:22:25 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

void    ft_free_map(char **map)
{
    int i;

    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int ft_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    ft_free_map(data->maps);
    exit(0);
    return (0);
}