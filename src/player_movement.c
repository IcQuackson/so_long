/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:46:30 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 16:37:57 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_player_position_valid(t_game *game_data, int x, int y)
{
	return (x > 0 && x < game_data->height
		&& y > 0 && y < game_data->width
		&& game_data->map[x][y] != '1');
}

void	check_if_game_over(t_game *game_data, int new_x, int new_y)
{
	char	**map;

	map = game_data->map;
	if (map[new_x][new_y] == 'E' && game_data->collectibles == 0)
		destroy(game_data, "You win!\n");
	if (game_data->map[new_x][new_y] == 'S')
		destroy(game_data, "You lose!\n");
}

void	move_player(t_game *game_data, int new_x, int new_y)
{
	int		x;
	int		y;
	char	**map;

	x = game_data->player_x;
	y = game_data->player_y;
	map = game_data->map;
	if (is_player_position_valid(game_data, new_x, new_y))
	{
		game_data->moves += 1;
		ft_printf("Moves: %d\n", game_data->moves);
		check_if_game_over(game_data, new_x, new_y);
		if (map[new_x][new_y] == 'C')
			game_data->collectibles -= 1;
		map[x][y] = '0';
		if (x == game_data->exit_x && y == game_data->exit_y)
			map[x][y] = 'E';
		map[new_x][new_y] = 'P';
		game_data->player_x = new_x;
		game_data->player_y = new_y;
		paint_map(game_data);
		paint_counter(game_data);
	}
}
