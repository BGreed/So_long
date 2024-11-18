/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:50:25 by braugust          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:55 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define PLAYER "images/Player.xpm"
# define FLOOR "images/Floor.xpm"
# define WALL "images/Wall.xpm"
# define COINS "images/Coins.xpm"
# define EXIT "images/Exit.xpm"

# define SIZE 64
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define EXIT_WINDOWS 65307


typedef struct s_data
{
    void	*mlx;         // Pointeur pour MiniLibX
    void	*mlx_win;     // Fenêtre MiniLibX

    char	**maps;       // Tableau 2D contenant la carte
    char	*av1;         // Nom du fichier .ber

    int		lx;           // Largeur de la carte (nombre de colonnes)
    int		ly;           // Hauteur de la carte (nombre de lignes)
    int		px;           // Position X du joueur
    int		py;           // Position Y du joueur

    int     coin_collect;
    int		coin;         // Nombre de collectibles
    int		exit;         // Nombre de sorties
    int		player;       // Nombre de joueurs

    int		move;         // Compteur de mouvements

    void	*mlx_player;   // Image pour le joueur
    void	*mlx_floor;   // Image pour le sol
    void	*mlx_wall;    // Image pour les murs
    void	*mlx_coin;    // Image pour les collectibles
    void	*mlx_exit;    // Image pour la sortie
}	t_data;

int     ft_check_wall(t_data *data);
int     ft_check_char(t_data *data);
int     ft_check_valid(t_data *data);
int     ft_check_ber(char *str);
void    flood_fill(char **map, int x, int y, int *c, int *e);
int     ft_check_accessible(t_data *data);
void    ft_free_map(char **map);
int     ft_count_char(char **map, char c);
char    **ft_map_copy(char **map);
int     ft_find_player(char **map, int *x, int *y);
void	ft_load_images(t_data *data);
int 	ft_init_window(t_data *data);
int     ft_close(t_data *data);
void    ft_render_map(t_data *data);
int     ft_check_all(t_data *data);
int     ft_parsing(t_data *data);
void    ft_display_maps(char **str);
int     move_right(t_data *data);
int     ft_move(int keycode, t_data *data);
int     move_left(t_data *data);
int     move_down(t_data *data);
int     move_up(t_data *data);
int  update_scene(void *param);

#endif