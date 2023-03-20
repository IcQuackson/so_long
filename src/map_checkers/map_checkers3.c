/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:29:03 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/10 17:01:49 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
	- I create an auxiliary integer matrix and use it 
	with the Flood Fill algorithm to check if a valid
	path exists.
	- A valid path is path that allows the
	character to go from the starting point to the exit
	and collect ALL of the collectibles in the map.
*/
int	path_exists(char **map)
{
	int		collectibles;
	int		path_exists;
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	if (!map_data)
		return (0);
	map_data->map = map;
	get_size(map_data);
	map_data->matrix = get_matrix(map_data->height, map_data->width);
	if (!(map_data->matrix))
		return (0);
	set_matrix(map_data);
	print_matrix(map_data);
	collectibles = 0;
	path_exists = 0;
	if (flood_fill(map_data, map_data->start_x,
			map_data->start_y, &collectibles)
		&& collectibles == count_collectibles(map_data))
		path_exists = 1;
	free_matrix(map_data->matrix);
	free(map_data);
	return (path_exists);
}

/* 	Flood-fill (node):
	1. If node is not Inside return.
	2. Set the node
	3. Perform Flood-fill one step to the south of node.
	4. Perform Flood-fill one step to the north of node
	5. Perform Flood-fill one step to the west of node
	6. Perform Flood-fill one step to the east of node
	7. Return. */
int	flood_fill(t_map *map_data, int x, int y, int *collectibles)
{
	static int	is_path;
	int			**matrix;

	(void) collectibles;
	matrix = map_data->matrix;
	if (x < 0 || x >= map_data->height || y < 0
		|| y >= map_data->width || matrix[x][y] == 1)
		return (is_path);
	if (matrix[x][y] == 3)
		*collectibles = *collectibles + 1;
	else if (matrix[x][y] == 2)
		is_path = 1;
	if (matrix[x][y] == -1)
		return (is_path);
	matrix[x][y] = -1;
	flood_fill(map_data, x + 1, y, collectibles);
	flood_fill(map_data, x - 1, y, collectibles);
	flood_fill(map_data, x, y - 1, collectibles);
	flood_fill(map_data, x, y + 1, collectibles);
	return (is_path);
}

int	count_collectibles(t_map *mapa_data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (i < mapa_data->height)
	{
		while (j < mapa_data->width)
		{
			if (mapa_data->map[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	get_size(t_map *map_data)
{
	int		height;
	int		width;
	char	**map;

	map = map_data->map;
	height = 0;
	width = 0;
	while (map[height])
		height++;
	while (map[0][width])
		width++;
	map_data->height = height;
	map_data->width = width;
}

int	**get_matrix(int height, int width)
{
	int	i;
	int	**matrix;

	matrix = malloc((height + 1) * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = malloc(width * sizeof(int));
		if (!(matrix[i]))
		{
			free_matrix(matrix);
			return (NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
