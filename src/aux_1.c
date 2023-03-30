/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:55:03 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 17:31:28 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_imgs(t_game *game_data)
{
	int	img_width;
	int	img_height;

	game_data->space_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/water-sprite.xpm", &img_width, &img_height);
	game_data->player_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/dolphin-in-water.xpm", &img_width, &img_height);
	game_data->wall_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/wall on water.xpm", &img_width, &img_height);
	game_data->collect_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/fish.xpm", &img_width, &img_height);
	game_data->enemy_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/shark.xpm", &img_width, &img_height);
	game_data->exit_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/exit.xpm", &img_width, &img_height);
}

void	register_hooks(t_game *game_data)
{
	mlx_hook(game_data->win, KEY_PRESS_EVENT, KEY_PRESS_MASK,
		key_down_hook, game_data);
	mlx_hook(game_data->win, DESTROY_EVENT, KEY_PRESS_MASK,
		handle_closewindow, game_data);
	mlx_loop_hook(game_data->mlx, loop_hook, game_data);
}

void	paint_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->width * TILE_SIZE)
	{
		y = 0;
		while (y < g->height * TILE_SIZE)
		{
			if (g->map[y / 30][x / 30] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->wall_img, x, y);
			else if (g->map[y / 30][x / 30] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->space_img, x, y);
			else if (g->map[y / 30][x / 30] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->collect_img, x, y);
			else if (g->map[y / 30][x / 30] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->exit_img, x, y);
			else if (g->map[y / 30][x / 30] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->player_img, x, y);
			else if (g->map[y / 30][x / 30] == 'S')
				mlx_put_image_to_window(g->mlx, g->win, g->enemy_img, x, y);
			y += TILE_SIZE;
		}
		x += TILE_SIZE;
	}
}

void	destroy(t_game *game_data, const char *msg)
{
	if (msg)
		ft_printf(msg);
	mlx_destroy_image(game_data->mlx, game_data->player_img);
	mlx_destroy_image(game_data->mlx, game_data->space_img);
	mlx_destroy_image(game_data->mlx, game_data->wall_img);
	mlx_destroy_image(game_data->mlx, game_data->enemy_img);
	mlx_destroy_image(game_data->mlx, game_data->collect_img);
	mlx_destroy_image(game_data->mlx, game_data->exit_img);
	mlx_destroy_window(game_data->mlx, game_data->win);
	mlx_destroy_display(game_data->mlx);
	free(game_data->mlx);
	free_map(game_data->map);
	free(game_data->enemies);
	free(game_data);
	exit(0);
}

int	count_enemies(t_game *game_data)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < game_data->height)
	{
		j = 0;
		while (j < game_data->width)
		{
			if (game_data->map[i][j] == 'S')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
