/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/26 15:19:01 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/mlx_int.h"
#include "../includes/so_long.h"
#include "../includes/ft_printf.h"

#include <assert.h>

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game_data;

	game_data = (t_game *) malloc(sizeof(t_game));
	if (!game_data)
		return (0);
	if (argc != 2)
	{
		ft_printf("Error\nNot enough arguments\n");
		return (0);
	}
	map = get_map(argv[1], game_data);
	if (!map)
	{
		ft_printf("Error\nMisconfigured map\n");
		return (0);
	}
	int i = 0;
	printf("\n");
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	srand(time(0));
	ft_printf("height:%d width:%d\n", game_data->height, game_data->width);
	ft_printf("exit: x:%d y:%d\n", game_data->exit_x, game_data->exit_y);
	ft_printf("collectibles:%d\n", game_data->collectibles);
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, game_data->width * TILE_SIZE,
			game_data->height * TILE_SIZE, "Dolphin goes brrr");
	load_enemies(game_data);
	register_hooks(game_data);
	load_imgs(game_data);
	paint_map(game_data);
	game_data->moves = 0;
	game_data->frames = 0;
	load_animation_imgs(game_data);
	time(&(game_data->start_time));
	mlx_loop(game_data->mlx);
}
