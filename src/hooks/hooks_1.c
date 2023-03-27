/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:57 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/26 20:22:40 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_down_hook(int keycode, t_game *game_data)
{
	int	x;
	int	y;

	x = game_data->player_x;
	y = game_data->player_y;
	if (keycode == esc)
	{
		destroy(game_data, "");
	}
	else if (keycode == 'w')
		move(game_data, x - 1, y);
	else if (keycode == 's')
		move(game_data, x + 1, y);
	else if (keycode == 'a')
		move(game_data, x, y - 1);
	else if (keycode == 'd')
		move(game_data, x, y + 1);
	return (0);
}

int	handle_closewindow(t_game *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	free_map(game_data->map);
	exit(0);
}

int	key_up_hook(int keycode, t_game *game_data)
{
	(void) game_data;
	(void) keycode;
	return (0);
}

void	animate_collectibles(t_game *game_data)
{
	static int	index = 0;
	int			i;
	int			j;

	i = -1;
	while (++i < game_data->height)
	{
		j = -1;
		while (++j < game_data->width)
		{
			if (game_data->map[i][j] == 'C')
			{
				if (index == 0)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_2_down, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 1)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_1_down, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 2)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 3)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_1_up, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 4)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_2_up, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 5)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_3_up, i * TILE_SIZE, j * TILE_SIZE);
				else if (index == 6)
					mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->animation->fish_4_up, i * TILE_SIZE, j * TILE_SIZE);
			}
		}
	}
	index++;
	if (index == 8)
		index = 0;
}

int	loop_hook(t_game *game_data)
{
	static time_t last_move_time = 0;
    time_t current_time = time(NULL);
	static int	i = 0;

    if (current_time - last_move_time >= 2) {
        move_all_enemies(game_data);
        last_move_time = current_time;
    }
	if (i % 100 == 0)
	{
		animate_collectibles(game_data);
	}
	return (0);
}
