/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:01:05 by quackson          #+#    #+#             */
/*   Updated: 2023/03/23 12:53:46 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_matrix(t_map *map_data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_data->height)
	{
		j = -1;
		while (++j < map_data->width)
		{
			if (map_data->map[i][j] == '0' || map_data->map[i][j] == 'P')
				map_data->matrix[i][j] = 0;
			if (map_data->map[i][j] == 'P')
			{
				map_data->player_x = i;
				map_data->player_y = j;
			}
			else if (map_data->map[i][j] == '1')
				map_data->matrix[i][j] = 1;
			else if (map_data->map[i][j] == 'E')
				map_data->matrix[i][j] = 2;
			else if (map_data->map[i][j] == 'C')
				map_data->matrix[i][j] = 3;
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

void	print_matrix(t_map *map_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_data->height)
	{
		while (j < map_data->width)
		{
			ft_printf("%d", map_data->matrix[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}


