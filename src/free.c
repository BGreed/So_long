/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:52:23 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:23:05 by braugust         ###   ########.fr       */
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
void    ft_free_mlx(t_data *all)
{
    if (all->mlx_coin)
        mlx_destroy_image(all->mlx, all->mlx_coin);
    if (all->mlx_floor)
        mlx_destroy_image(all->mlx, all->mlx_floor);
    if (all->mlx_exit)
        mlx_destroy_image(all->mlx, all->mlx_exit);
    if (all->mlx_player)
        mlx_destroy_image(all->mlx, all->mlx_player);
    if (all->mlx_wall)
        mlx_destroy_image(all->mlx, all->mlx_wall);
}

int ft_close(t_data *data)
{
    ft_free_mlx(data);
    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    ft_free_map(data->maps);
    exit(0);
    return (0);
}