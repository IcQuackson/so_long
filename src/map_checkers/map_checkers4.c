/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:01:05 by quackson          #+#    #+#             */
/*   Updated: 2023/03/24 12:19:34 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_matrix(t_game *game_data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game_data->height)
	{
		j = -1;
		while (++j < game_data->width)
		{
			if (game_data->map[i][j] == '0' || game_data->map[i][j] == 'P')
				game_data->matrix[i][j] = 0;
			if (game_data->map[i][j] == 'P')
			{
				game_data->player_x = i;
				game_data->player_y = j;
			}
			else if (game_data->map[i][j] == '1' || game_data->map[i][j] == 'S')
				game_data->matrix[i][j] = 1;
			else if (game_data->map[i][j] == 'E')
				game_data->matrix[i][j] = 2;
			else if (game_data->map[i][j] == 'C')
				game_data->matrix[i][j] = 3;
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

void	print_matrix(t_game *game_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game_data->height)
	{
		while (j < game_data->width)
		{
			ft_printf("%d", game_data->matrix[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_printf("\n");
	}
}
