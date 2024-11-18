/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:03:49 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 04:41:14 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        return (ft_putendl_fd("Error\nUsage: ./so_long <map.ber>", 2), EXIT_FAILURE);
    data.av1 = argv[1];
    if (ft_check_ber(data.av1) != 0)
        return (EXIT_FAILURE);
    data.mlx = mlx_init();
    if (!data.mlx)
        return (ft_putendl_fd("Error\nFailed to initialize MLX", 2), EXIT_FAILURE);
    data.mlx_win = mlx_new_window(data.mlx, data.lx * SIZE, data.ly * SIZE, "so_long");
    if (!data.mlx_win)
        return (ft_putendl_fd("Error\nFailed to create window", 2), EXIT_FAILURE);
    ft_load_images(&data);
    ft_render_map(&data);
    mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
    mlx_loop(data.mlx);

    return (0);
}

