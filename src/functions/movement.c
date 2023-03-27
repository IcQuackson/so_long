

#include "../../includes/so_long.h"

/* void	move(t_game *game_data, int x_change, int y_change)
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	char	**map;

	x = game_data->player_x;
	y = game_data->player_y;
	new_x = x + x_change;
	new_y = y + y_change;
	map = game_data->map;
	if (is_position_valid(game_data, new_x, new_y))
	{
		if (map[new_x][new_y] == 'E' && game_data->collectibles == 0)
			destroy(game_data);
		if (map[new_x][new_y] == 'C')
			game_data->collectibles -= 1;
		map[x][y] = '0';
		ft_printf("exit: x:%d y:%d\n", game_data->exit_x, game_data->exit_y);
		if (x == game_data->exit_x && y == game_data->exit_y)
			map[x][y] = 'E';
		map[new_x][new_y] = 'P';
		game_data->player_x = new_x;
		game_data->player_y = new_y;
		paint_movement(game_data, x, y);
	}
} */

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

int	is_player_position_valid(t_game *game_data, int x, int y)
{
	if (x > 0 && x < game_data->height
		&& y > 0 && y < game_data->width
		&& game_data->map[x][y] != '1')
	{
		/* counter = ft_itoa(game_data->moves);
		mlx_put_image_to_window(game_data->mlx, game_data->win,
			game_data->wall_img, 0, 0);
		mlx_string_put(game_data->mlx, game_data->win,
			10, 10, 0x00ff00, counter);
		free(counter); */
		return (1);
	}
	return (0);
}

void	move(t_game *game_data, int new_x, int new_y)
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
		if (map[new_x][new_y] == 'E' && game_data->collectibles == 0)
			destroy(game_data, "You win!\n");
		if (game_data->map[new_x][new_y] == 'S')
			destroy(game_data, "You lose!\n");
		if (map[new_x][new_y] == 'C')
			game_data->collectibles -= 1;
		ft_printf("Moves: %d\n", game_data->moves);
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
	else if (i == 1 && is_enemy_position_valid(game_data, *x, *y + change))
		(*y) += change;

}

/* void	get_random_movement(t_game *game_data, int *x, int *y)
{
	int	i;

	i = rand() % 4;
	//ft_printf("i: %d\n", i);
	if (i == 0 && is_enemy_position_valid(game_data, x + 1, y))
		(*x)++;
	else if (i == 1 && is_enemy_position_valid(game_data, x - 1, y))
		(*x)--;
	else if (i == 2 && is_enemy_position_valid(game_data, x, y + 1))
		(*y)++;
	else if (i == 3 && is_enemy_position_valid(game_data, x, y - 1))
		(*y)--;
	else
		(*x) = -1;
} */

void	move_all_enemies(t_game *game_data)
{
	int		i;
	t_enemy	*enemies;

	enemies = game_data->enemies;
	i = 0;
	while (i < game_data->enemy_count)
	{
		move_enemy(game_data, enemies + i);
		i++;
	}
	paint_map(game_data);
	paint_counter(game_data);
}

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

int	is_enemy_position_valid(t_game *game_data, int x, int y)
{
	return (x > 0 && x < game_data->height
		&& y > 0 && y < game_data->width
		&& game_data->map[x][y] != '1' && game_data->map[x][y] != 'E'
		&& game_data->map[x][y] != 'C' && game_data->map[x][y] != 'S');
}




/* void	paint_movement(t_game *game_data, int old_x, int old_y)
{
	void	*img;

	if (old_x == game_data->exit_x && old_y == game_data->exit_y)
		img = game_data->exit_img;
	else
		img = game_data->space_img;
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		img, old_y * TILE_SIZE, old_x * TILE_SIZE);
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->player_img, game_data->player_y * TILE_SIZE,
		game_data->player_x * TILE_SIZE);
} */

