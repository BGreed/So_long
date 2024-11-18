/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:34:09 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 10:11:09 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

int move_up(t_data *data)
{
    char next_pos = data->maps[data->py - 1][data->px];

    if (next_pos == '1')
        return (EXIT_FAILURE);
    if (next_pos == 'E' && data->coin_collect > 0)
        return (EXIT_FAILURE);
    if (next_pos == 'C')
        data->coin_collect--;

    data->maps[data->py][data->px] = '0';
    data->maps[data->py - 1][data->px] = 'P';
    data->py--;

    return (EXIT_SUCCESS);
}

int move_down(t_data *data)
{
    char next_pos = data->maps[data->py + 1][data->px];

    if (next_pos == '1')
        return (EXIT_FAILURE);
    if (next_pos == 'E' && data->coin_collect > 0)
        return (EXIT_FAILURE);
    if (next_pos == 'C')
        data->coin_collect--;

    data->maps[data->py][data->px] = '0';
    data->maps[data->py + 1][data->px] = 'P';
    data->py++;

    return (EXIT_SUCCESS);
}

int move_left(t_data *data)
{
    char next_pos = data->maps[data->py][data->px - 1];

    if (next_pos == '1')
        return (EXIT_FAILURE);
    if (next_pos == 'E' && data->coin_collect > 0)
        return (EXIT_FAILURE);
    if (next_pos == 'C') 
        data->coin_collect--;

    data->maps[data->py][data->px] = '0';
    data->maps[data->py][data->px - 1] = 'P';
    data->px--;

    return (EXIT_SUCCESS);
}

int move_right(t_data *data)
{
    char next_pos = data->maps[data->py][data->px + 1];

    if (next_pos == '1')
        return (EXIT_FAILURE);
    if (next_pos == 'E' && data->coin_collect > 0)
        return (EXIT_FAILURE);
    if (next_pos == 'C')
        data->coin_collect--;
    data->maps[data->py][data->px] = '0';
    data->maps[data->py][data->px + 1] = 'P';
    data->px++;

    return (EXIT_SUCCESS);
}

int ft_move(int keycode, t_data *data)
{
    int exit_status = EXIT_FAILURE;

    if (data->coin_collect == 0 && data->maps[data->py][data->px] == 'E')
        ft_close(data);
    if (keycode == W_KEY)
        exit_status = move_up(data);
    else if (keycode == S_KEY)
        exit_status = move_down(data);
    else if (keycode == A_KEY)
        exit_status = move_left(data);
    else if (keycode == D_KEY)
        exit_status = move_right(data);
    if (exit_status == EXIT_SUCCESS)
    {
        data->move++;
        ft_render_map(data);
        printf("Moves: %d\n", data->move);
        if (data->coin == 0 && data->maps[data->py][data->px] == 'E')
        {
            printf("YOU WIN !!\n");
            ft_close(data);
        }
    }
    return (exit_status);
}
