/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:02:00 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 03:20:43 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_images(t_data *data)
{
	data->mlx_player = mlx_xpm_file_to_image(data->mlx, PLAYER, &data->lx, &data->ly);
	data->mlx_floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &data->lx, &data->ly);
	data->mlx_wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->lx, &data->ly);
	data->mlx_coin = mlx_xpm_file_to_image(data->mlx, COINS, &data->lx, &data->ly);
	data->mlx_exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->lx, &data->ly);

	if (!data->mlx_player || !data->mlx_floor || !data->mlx_wall
		|| !data->mlx_coin || !data->mlx_exit)
	{
		ft_putendl_fd("Error\nFailed to load textures", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putendl_fd("Error\nFailed to initialize MiniLibX", 2);
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->lx * SIZE,
			data->ly * SIZE, "so_long");
	if (!data->mlx_win)
	{
		ft_putendl_fd("Error\nFailed to create window", 2);
		exit(EXIT_FAILURE);
	}
}

void ft_render_map(t_data *data)
{
    int x, y;

    y = 0;
    while (data->maps[y])
    {
        x = 0;
        while (data->maps[y][x])
        {
            if (data->maps[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_wall, x * SIZE, y * SIZE);
            else if (data->maps[y][x] == 'P')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_player, x * SIZE, y * SIZE);
            else if (data->maps[y][x] == 'C')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_coin, x * SIZE, y * SIZE);
            else if (data->maps[y][x] == 'E')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_exit, x * SIZE, y * SIZE);
            else
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_floor, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}
