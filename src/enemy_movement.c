/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:47:52 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 17:29:19 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy(t_game *game_data, t_enemy *enemy)
{
	int		new_x;
	int		new_y;
	char	**map;

	new_x = enemy->x;
	new_y = enemy->y;
	get_random_movement(game_data, enemy, &new_x, &new_y);
	map = game_data->map;
	if (is_enemy_position_valid(game_data, new_x, new_y))
	{
		if (new_x == game_data->player_x && new_y == game_data->player_y)
			destroy(game_data, "You lost!\n");
		map[enemy->x][enemy->y] = '0';
		map[new_x][new_y] = 'S';
		enemy->x = new_x;
		enemy->y = new_y;
	}
}

int	can_move(t_game *game_data, t_enemy *enemy)
{
	int	x;
	int	y;

	x = enemy->x;
	y = enemy->y;
	return (is_enemy_position_valid(game_data, x + 1, y)
		|| is_enemy_position_valid(game_data, x - 1, y)
		|| is_enemy_position_valid(game_data, x, y + 1)
		|| is_enemy_position_valid(game_data, x, y - 1));
}

void	get_random_movement(t_game *game_data, t_enemy *enemy, int *x, int *y)
{
	int	i;
	int	change;

	if (!can_move(game_data, enemy))
		return ;
	i = rand() % 2;
	change = rand() % 2;
	if (change == 0)
		change = -1;
	if (i == 0 && is_enemy_position_valid(game_data, *x + change, *y))
		(*x) += change;
	else if (i == 0 && is_enemy_position_valid(game_data, *x + -change, *y))
		(*x) += -change;
	else if (i == 1 && is_enemy_position_valid(game_data, *x, *y + change))
		(*y) += change;
	else if (i == 1 && is_enemy_position_valid(game_data, *x, *y + -change))
		(*y) += -change;
}

int	is_enemy_position_valid(t_game *game_data, int x, int y)
{
	return (x > 0 && x < game_data->height
		&& y > 0 && y < game_data->width
		&& game_data->map[x][y] != '1' && game_data->map[x][y] != 'E'
		&& game_data->map[x][y] != 'C' && game_data->map[x][y] != 'S');
}

void	move_all_enemies(t_game *game_data)
{
	int		i;
	t_enemy	*enemies;

	enemies = game_data->enemies;
	i = 0;
	while (i < game_data->enemy_count)
	{
		move_enemy(game_data, &enemies[i]);
		i++;
	}
	paint_map(game_data);
	paint_counter(game_data);
}
