/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:47 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 17:47:04 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_matrix_size
{
	int	h;
	int	w;
}	t_matrix_size;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;


char			**get_map(char *file_name);
int				check_characters(char **map);
int				error(const char *msg);
void			free_map(char **map);
int				is_rectangular(char **map);
int				is_horizontal_wall(char *line);
char			**get_map_from_file(char *file_name);
int				count_lines(char *file_name);
int				check_vertical_walls(char **map);
int				check_components(char **map);
int				path_exists(char	**map);
int				**get_matrix(int height, int width);
void			set_matrix(int **matrix, char **map, int height, int width);
void			free_matrix(int **matrix);
void			print_matrix(int **matrix, int height, int width);
int				flood_fill(int **matrix, int x, int y, t_matrix_size *size);
t_matrix_size	*get_size(char **map);
t_coord			*get_start(char **map, int height, int width);

#endif