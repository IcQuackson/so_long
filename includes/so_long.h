/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:16:47 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/26 20:12:50 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx.h"
# include <fcntl.h>
# include <time.h>


# define WIDTH 640
# define HEIGHT 480
# define TILE_SIZE 30

enum e_key_codes
{
	esc = 65307,
	w = 119,
	a = 97,
	s = 115,
	d = 100
};

enum e_masks
{
	key_press_mask = (1L<<0)
};

enum e_events
{
	key_press_event = 2,
	destroy_event = 17
};

typedef struct s_animation
{
	void	*fish_2_down;
	void	*fish_1_down;
	void	*fish;
	void	*fish_1_up;
	void	*fish_2_up;
	void	*fish_3_up;
	void	*fish_4_up;
}	t_animation;


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
	void		**fish_imgs;

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

	void		*collect_imgs[7];
	t_animation	*animation;
	int			frames;
	time_t		start_time;
}	t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
void		load_animation_imgs(t_game *game_data);

/* HOOKS */
int			key_down_hook(int keycode, t_game *game_data);
int			handle_closewindow(t_game *game_data);
int			key_up_hook(int keycode, t_game *game_data);
int			mouse_hook(int button, int x, int y, t_game *game_data);
int			loop_hook(t_game *game_data);

void		load_imgs(t_game *game_data);
void		register_hooks(t_game *game_data);
void		paint_map(t_game *game_data);

/* MOVEMENT */
void		move_all_enemies(t_game *game_data);
int			is_enemy_position_valid(t_game *game_data, int x, int y);
void		get_random_movement(t_game *g_data, t_enemy *enemy, int *x, int *y);
void		move_enemy(t_game *game_data, t_enemy *enemy);
void		move_up(t_game *game_data);
void		move_down(t_game *game_data);
void		move_left(t_game *game_data);
void		move_right(t_game *game_data);
void		move(t_game *game_data, int new_x, int new_y);
void		paint_movement(t_game *game_data, int new_x, int new_y);
void		get_player_and_exit(t_game *game_data);
int			is_player_position_valid(t_game *game_data, int x, int y);

#endif