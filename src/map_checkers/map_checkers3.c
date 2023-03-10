/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:29:03 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 17:47:45 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	path_exists(char **map)
{
	int				**matrix;
	t_matrix_size	*size;
	t_coord			*start;

	size = get_size(map);
	matrix = get_matrix(size->h, size->w);
	if (!matrix)
		return (0);
	set_matrix(matrix, map, size->h, size->w);
	print_matrix(matrix, size->h, size->w);
	start = get_start(map, size->h, size->w);
	ft_printf("x:%d y:%d\n", start->x, start->y);
	ft_printf("path_exists: %d\n", flood_fill(matrix, start->x, start->y, size));
	free(start);
	free_matrix(matrix);
	free(size);
	return (1);
}

/* 	Flood-fill (node):
	1. If node is not Inside return.
	2. Set the node
	3. Perform Flood-fill one step to the south of node.
	4. Perform Flood-fill one step to the north of node
	5. Perform Flood-fill one step to the west of node
	6. Perform Flood-fill one step to the east of node
	7. Return. */
int	flood_fill(int **matrix, int x, int y, t_matrix_size *size)
{
	static int	is_path;

	if (x < 0 || x >= size->h || y < 0 || y >= size->w || matrix[x][y] == 1)
		return (is_path);
	if (matrix[x][y] == 2)
	{
		is_path = 1;
		return (is_path);
	}
	if (matrix[x][y] == -1)
		return (is_path);
	matrix[x][y] = -1;
	flood_fill(matrix, x + 1, y, size);
	flood_fill(matrix, x - 1, y, size);
	flood_fill(matrix, x, y - 1, size);
	flood_fill(matrix, x, y + 1, size);
	return (is_path);
}

t_coord	*get_start(char **map, int height, int width)
{
	int		i;
	int		j;
	t_coord	*start;

	start = malloc(sizeof(t_coord));
	if (!start)
		return (NULL);
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (map[i][j] == 'P')
			{
				start->x = i;
				start->y = j;
				return (start);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

t_matrix_size	*get_size(char **map)
{
	int				height;
	int				width;
	t_matrix_size	*size;

	height = 0;
	width = 0;
	while (map[height])
		height++;
	while (map[0][width])
		width++;
	size = malloc(sizeof(t_matrix_size));
	if (!size)
		return (NULL);
	size->h = height;
	size->w = width;
	return (size);
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

void	set_matrix(int **matrix, char **map, int height, int width)
{
	int		i;
	int		j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == '0' || map[i][j] == 'P')
				matrix[i][j] = 0;
			else if (map[i][j] == '1')
				matrix[i][j] = 1;
			else if (map[i][j] == 'E')
				matrix[i][j] = 2;
		}
	}
}

void	free_matrix(int **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix[i]);
	free(matrix);
}

void	print_matrix(int **matrix, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			ft_printf("%d", matrix[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}



