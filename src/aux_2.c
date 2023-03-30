/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:55:30 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 14:57:46 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_enemies(t_game *game_data)
{
	int		i;
	int		j;
	int		k;

	game_data->enemies = NULL;
	game_data->enemy_count = count_enemies(game_data);
	if (game_data->enemy_count == 0)
		return ;
	game_data->enemies = malloc(game_data->enemy_count * sizeof(t_enemy));
	if (!(game_data->enemies))
		destroy(game_data, "ERROR\n");
	k = 0;
	i = -1;
	while (++i < game_data->height)
	{
		j = -1;
		while (++j < game_data->width)
		{
			if (game_data->map[i][j] == 'S')
			{
				game_data->enemies[k].x = i;
				game_data->enemies[k++].y = j;
			}
		}
	}
}

void	paint_counter(t_game *game_data)
{
	char	*counter;

	counter = ft_itoa(game_data->moves);
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->wall_img, 0, 0);
	mlx_string_put(game_data->mlx, game_data->win,
		10, 10, 0x00ff00, counter);
	free(counter);
}
