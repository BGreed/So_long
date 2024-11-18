/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 03:34:51 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 06:09:58 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_parsing(t_data *data)
{
    int fd;
    char *line;
    char *temp_map;
    char *full_map;

    full_map = NULL;
    fd = open(data->av1, O_RDONLY);
    if (fd < 0)
        return (ft_putendl_fd("Error\nFailed to open the map file.", 2), EXIT_FAILURE);
    while ((line = get_next_line(fd)))
    {
        temp_map = full_map;
        full_map = ft_strjoin(temp_map, line);
        free(temp_map);
        free(line);
        if (!full_map)
            return (ft_putendl_fd("Error\nMemory allocation failed.", 2), EXIT_FAILURE);
    }
    close(fd);
    data->maps = ft_split(full_map, '\n');
    free(full_map);
    if (!data->maps || !data->maps[0])
        return (ft_putendl_fd("Error\nMap is empty or invalid.", 2), EXIT_FAILURE);
    data->ly = 0;
    while (data->maps[data->ly])
        data->ly++;
    data->lx = ft_strlen(data->maps[0]);
    if (data->lx <= 0 || data->ly <= 0)
        return (ft_putendl_fd("Error\nInvalid map dimensions", 2), EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
