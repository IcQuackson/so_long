/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:47 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 17:27:03 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <time.h>

# define WIDTH 640
# define HEIGHT 480
# define TILE_SIZE 30
# define ESC 65307
# define KEY_PRESS_EVENT 2 
# define KEY_PRESS_MASK 1L
# define DESTROY_EVENT 17

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*player_img;
	void		*space_img;
	void		*wall_img;
	void		*enemy_img;
	void		*collect_img;
	void		*exit_img;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collectibles;
	int			moves;
	int			height;
	int			width;
	int			**matrix;
	char		**map;
	t_enemy		*enemies;
	int			enemy_count;
	time_t		start_time;
}	t_game;

char		**get_map(char *file_name, t_game *game_data);
int			check_characters(char **map);
int			error(const char *msg);
void		free_map(char **map);
int			is_rectangular(char **map);
int			is_horizontal_wall(char *line);
char		**get_map_from_file(char *file_name);
int			count_lines(char *file_name);
int			check_vertical_walls(char **map);
int			check_components(char **map);
int			path_exists(char **map, t_game *game_data);
int			**get_matrix(int height, int width);
void		set_matrix(t_game *game_data);
void		free_matrix(int **matrix);
void		print_matrix(t_game *game_data);
int			flood_fill(t_game *game_data, int x, int y, int *collectibles);
void		get_size(t_game *game_data);
int			count_collectibles(t_game *game_data);
void		destroy(t_game *game_data, const char *msg);
void		load_enemies(t_game *game_data);
int			count_enemies(t_game *game_data);
void		load_game(t_game *game_data);

/* HOOKS */
int			key_down_hook(int keycode, t_game *game_data);
int			handle_closewindow(t_game *game_data);
int			loop_hook(t_game *game_data);
void		register_hooks(t_game *game_data);

void		load_imgs(t_game *game_data);
void		paint_counter(t_game *game_data);
void		paint_map(t_game *game_data);

/* MOVEMENT */
void		move_player(t_game *game_data, int new_x, int new_y);
int			is_player_position_valid(t_game *game_data, int x, int y);
void		check_if_game_over(t_game *game_data, int new_x, int new_y);
void		move_enemy(t_game *game_data, t_enemy *enemy);
int			is_enemy_position_valid(t_game *game_data, int x, int y);
void		get_random_movement(t_game *g_data, t_enemy *enemy, int *x, int *y);
void		move_all_enemies(t_game *game_data);

#endif