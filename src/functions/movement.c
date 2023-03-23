

#include "../../includes/so_long.h"

int	move(t_game *game_data, int x_change, int y_change)
{
	int		x;
	int		y;
	int		new_x;
	int		new_y;
	char	**map;

	x = game_data->map_data->player_x;
	y = game_data->map_data->player_y;
	new_x = x + x_change;
	new_y = y + y_change;
	map = game_data->map_data->map;
	if (new_x > 0 && new_x < game_data->map_data->height
		&& new_y > 0 && new_y < game_data->map_data->width
		&& map[new_x][new_y] != '1')
	{
		ft_printf("%c\n", map[new_x][new_y]);
		paint_movement(game_data, new_x, new_y);
		map[x][y] = map[new_x][new_y];
		map[new_x][new_y] = 'P';
		game_data->map_data->player_x = new_x;
		game_data->map_data->player_y = new_y;
		ft_printf("new_x:%d new_y:%d\n", game_data->map_data->player_x, game_data->map_data->player_y);
		return (1);
	}
	else
		return (0);
}

void	paint_movement(t_game *game_data, int new_x, int new_y)
{
	void	*img;
	char	**map;

	map = game_data->map_data->map;
	if (map[new_x][new_y] == '0')
		img = game_data->space_img;
	else if (map[new_x][new_y] == 'E')
		img = game_data->space_img;
	else if (map[new_x][new_y] == 'C')
		img = game_data->space_img;
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		game_data->player_img, game_data->map_data->player_x * TILE_SIZE,
		game_data->map_data->player_y * TILE_SIZE);
	mlx_put_image_to_window(game_data->mlx, game_data->win,
		img, new_x * TILE_SIZE, new_y * TILE_SIZE);
}
