

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
	game_data->collect_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/fish.xpm", &img_width, &img_height);
	game_data->enemy_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/shark.xpm", &img_width, &img_height);
	game_data->exit_img = mlx_xpm_file_to_image(game_data->mlx,
			"./imgs/exit.xpm", &img_width, &img_height);
}

void	register_hooks(t_game *game_data)
{
	mlx_hook(game_data->win, key_press_event, key_press_mask,
		key_down_hook, game_data);
	mlx_hook(game_data->win, destroy_event, key_press_mask,
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
	mlx_destroy_window(game_data->mlx, game_data->win);
	free_map(game_data->map);
	free(game_data->enemies);
	free(game_data->fish_imgs);
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

void	load_animation_imgs(t_game *game_data)
{
	static char	**imgs;
	int			img_width;
	int			img_height;

	imgs = (char *[]){"./imgs/fish_2_down.xpm", "./imgs/fish_1_down.xpm",
		"./imgs/fish.xpm", "./imgs/fish_1_up.xpm", "./imgs/fish_2_up.xpm",
		"./imgs/fish_3_up.xpm", "./imgs/fish_4_up.xpm"};

	game_data->animation = malloc(sizeof(t_animation));
	if (!(game_data->animation))
		destroy(game_data, "ERROR!\n");
	game_data->animation->fish_2_down = mlx_xpm_file_to_image(game_data->mlx,
			imgs[0], &img_width, &img_height);
	game_data->animation->fish_1_down = mlx_xpm_file_to_image(game_data->mlx,
			imgs[1], &img_width, &img_height);
	game_data->animation->fish = mlx_xpm_file_to_image(game_data->mlx,
			imgs[2], &img_width, &img_height);
	game_data->animation->fish_1_up = mlx_xpm_file_to_image(game_data->mlx,
			imgs[3], &img_width, &img_height);
	game_data->animation->fish_2_up = mlx_xpm_file_to_image(game_data->mlx,
			imgs[4], &img_width, &img_height);
	game_data->animation->fish_3_up = mlx_xpm_file_to_image(game_data->mlx,
			imgs[5], &img_width, &img_height);
	game_data->animation->fish_4_up = mlx_xpm_file_to_image(game_data->mlx,
			imgs[6], &img_width, &img_height);
}
