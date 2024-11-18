/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:16:38 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 03:26:32 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_check_wall(t_data *data)
{
    int i;
    int len;

    len = ft_strlen(data->maps[0]);
    i = -1;
    while (data->maps[++i])
    {
        if ((int)ft_strlen(data->maps[i]) != len)
            return(ft_putendl_fd("Error\nMap Not Rectangle", 2), EXIT_FAILURE);
    }
    i = 0;
    while (++i < len)
    {
        if (data->maps[0][i] != '1' || data->maps[i][0] != '1')
            return(ft_putendl_fd("Error\nWall Not ClosedH", 2), EXIT_FAILURE);
    }
    i = 0;
    while (data->maps[++i])
    {
        if (data->maps[i][0] != '1'|| data->maps[i][len - 1] != '1')
            return (ft_putendl_fd("Error\nWall Not ClosedC", 2), EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int ft_check_char(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->maps[i])
    {
        j = 0;
        while (data->maps[i][j])
        {
            if (data->maps[i][j] != '1' && data->maps[i][j] != '0' && 
                data->maps[i][j] != 'P' && data->maps[i][j] != 'C' && 
                data->maps[i][j] != 'E')
                return (ft_putendl_fd("Error\nInvalid Character in Map", 2), EXIT_FAILURE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int ft_check_valid(t_data *data)
{
    int i;
    int j;
    int count[3];

    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    i = -1;
    while (data->maps[++i])
    {
        j = -1;
        while (data->maps[i][++j])
        {
            if (data->maps[i][j] == 'P')
                count[0]++;
            else if (data->maps[i][j] == 'E')
                count[1]++;
            else if (data->maps[i][j] == 'C')
                count[2]++;
        }
    }
    if (count[0] != 1 || count[1] < 1 || count[2] < 1)
        return (ft_putendl_fd("Error\nInvalid map elements", 2), EXIT_FAILURE);
    return (EXIT_SUCCESS);
}


int ft_check_ber(char *str)
{
    int len;

    if (!str)
        return (1);
    len = ft_strlen(str);
    if (len < 4 || ft_strncmp(str + len - 4, ".ber", 4) != 0)
        return (1);
    return (0);
}

int ft_run_checks(t_data *data)
{
    if (ft_check_ber(data->av1) != 0)
        return (ft_putendl_fd("Error\nInvalid file extension. Must be .ber", 2), EXIT_FAILURE);
    if (ft_check_wall(data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    if (ft_check_char(data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    if (ft_check_valid(data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    if (ft_check_accessible(data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}