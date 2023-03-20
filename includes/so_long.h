/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:47 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/20 13:55:56 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx.h"
# include <fcntl.h>


enum e_key_codes
{
	esc = 65307,
	w = 119,
	a = 97,
	s = 115,
	d = 100
};

enum e_masks
{
	key_press_mask = (1L<<0)
};

enum e_events
{
	key_press_event = 2,
	destroy_event = 17
};

typedef struct s_map
{
	int		start_x;
	int		start_y;
	int		height;
	int		width;
	int		**matrix;
	char	**map;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

char		**get_map(char *file_name);
int			check_characters(char **map);
int			error(const char *msg);
void		free_map(char **map);
int			is_rectangular(char **map);
int			is_horizontal_wall(char *line);
char		**get_map_from_file(char *file_name);
int			count_lines(char *file_name);
int			check_vertical_walls(char **map);
int			check_components(char **map);
int			path_exists(char	**map);
int			**get_matrix(int height, int width);
void		set_matrix(t_map *map_data);
void		free_matrix(int **matrix);
void		print_matrix(t_map *map_data);
int			flood_fill(t_map *map_data, int x, int y, int *collectibles);
void		get_size(t_map *map_data);
int			count_collectibles(t_map *mapa_data);

/* HOOKS */
int			close_window_esc(int keycode, t_vars *vars);
int			close_win_cross(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int button, int x, int y, t_vars *vars);
#endif