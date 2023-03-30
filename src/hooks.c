/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:57 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 18:36:01 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_down_hook(int keycode, t_game *game_data)
{
	int	x;
	int	y;

	x = game_data->player_x;
	y = game_data->player_y;
	if (keycode == ESC)
		destroy(game_data, "");
	else if (keycode == 'w')
		move_player(game_data, x - 1, y);
	else if (keycode == 's')
		move_player(game_data, x + 1, y);
	else if (keycode == 'a')
		move_player(game_data, x, y - 1);
	else if (keycode == 'd')
		move_player(game_data, x, y + 1);
	return (0);
}

int	handle_closewindow(t_game *game_data)
{
	destroy(game_data, "");
	return (0);
}

int	loop_hook(t_game *game_data)
{
	static time_t	last_move_time = 0;
	time_t			current_time;

	current_time = time(NULL);
	if (current_time - last_move_time >= 1)
	{
		move_all_enemies(game_data);
		last_move_time = current_time;
	}
	return (0);
}
