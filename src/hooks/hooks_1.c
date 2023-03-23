/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:57 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/22 22:16:23 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_down_hook(int keycode, t_game *game_data)
{
	if (keycode == esc)
	{
		mlx_destroy_window(game_data->mlx, game_data->win);
		free_map(game_data->map_data->map);
		exit(0);
	}
	else if (keycode == 'w' && move(game_data, -1, 0))
	{
		paint_map(game_data);
		ft_printf("%c\n", keycode);
	}
	else if (keycode == 's' && move(game_data, 1, 0))
	{
		paint_map(game_data);
		ft_printf("%c\n", keycode);
	}
	else if (keycode == 'a' && move(game_data, 0, -1))
	{
		paint_map(game_data);
		ft_printf("%c\n", keycode);
	}
	else if (keycode == 'd' && move(game_data, 0, 1))
	{
		paint_map(game_data);
		ft_printf("%c\n", keycode);
	}
	return (0);
}

int	handle_closewindow(t_game *game_data)
{
	mlx_destroy_window(game_data->mlx, game_data->win);
	free_map(game_data->map_data->map);
	exit(0);
}

int	key_up_hook(int keycode, t_game *game_data)
{
	(void) game_data;
	(void) keycode;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_game *game_data)
{
	(void) x;
	(void) y;
	(void) game_data;
	ft_printf("Hello from key_hook! %d\n", button);
	return (0);
}
