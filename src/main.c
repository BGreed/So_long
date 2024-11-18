/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:03:49 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 06:15:56 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        return (ft_putendl_fd("Error\nUsage: ./so_long <map.ber>", 2), EXIT_FAILURE);
    data.av1 = argv[1];
    if (ft_parsing(&data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    if (ft_check_all(&data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    ft_init_window(&data);
    ft_load_images(&data);
    ft_render_map(&data);
    mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
    mlx_loop(data.mlx);

    return (EXIT_SUCCESS);
}

