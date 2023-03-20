/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:47 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/10 16:33:16 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_map
{
	int		start_x;
	int		start_y;
	int		height;
	int		width;
	int		**matrix;
	char	**map;
}	t_map;

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

#endif