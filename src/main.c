/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/23 14:37:07 by quackson         ###   ########.fr       */
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
	t_map	*map_data;
	t_game	*game_data;

	game_data = (t_game *) malloc(sizeof(t_game));
	if (!game_data)
		return (0);
	map_data = (t_map *) malloc(sizeof(t_map));
	if (!map_data)
		return (0);
	if (argc != 2)
	{
		ft_printf("Error\nNot enough arguments\n");
		return (0);
	}
	map = get_map(argv[1], map_data);
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
	game_data->map_data = map_data;
	ft_printf("height:%d width:%d\n", game_data->map_data->height, game_data->map_data->width);
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx, map_data->width * TILE_SIZE,
			map_data->height * TILE_SIZE, "Dolphin goes brrr");
	register_hooks(game_data);
	load_imgs(game_data);
	paint_map(game_data);
	mlx_loop(game_data->mlx);
}
