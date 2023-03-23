

#include "../../includes/so_long.h"

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
	/* game_data->collectible_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/fish.xpm", &img_width, &img_height);
	game_data->enemy_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/shark.xpm", &img_width, &img_height);
	game_data->exit_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/exit.xpm", &img_width, &img_height); */
}

void	register_hooks(t_game *game_data)
{
	mlx_hook(game_data->win, key_press_event, key_press_mask,
		key_down_hook, game_data);
	mlx_hook(game_data->win, destroy_event, key_press_mask,
		handle_closewindow, game_data);
	mlx_mouse_hook(game_data->win, mouse_hook, game_data);
	mlx_key_hook(game_data->win, key_up_hook, game_data);
}

void	paint_map(t_game *game_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game_data->map_data->width * TILE_SIZE)
	{
		while (y < game_data->map_data->height * TILE_SIZE)
		{
			if (game_data->map_data->map[y / 30][x / 30] == '1')
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->wall_img, x, y);
			else if (game_data->map_data->map[y / 30][x / 30] == '0')
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->space_img, x, y);
			else if (game_data->map_data->map[y / 30][x / 30] == 'P')
				mlx_put_image_to_window(game_data->mlx, game_data->win,
					game_data->player_img, x, y);
			y += TILE_SIZE;
		}
		y = 0;
		x += TILE_SIZE;
	}
}

/* void	get_player_and_exit(t_map *map_data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_data->height)
	{
		j = -1;
		while (++j < map_data->width)
		{
			if (map_data->map[i][j] == 'P')
			{
				map_data->player_x = i;
				map_data->player_y = j;
			}
			else if (map_data->map[i][j] == 'E')
			{
				map_data->exit_x = i;
				map_data->exit_y = j;
			}
		}
	}
} */