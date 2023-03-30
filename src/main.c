/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/27 18:08:47 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <assert.h>

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game_data;

	if (argc != 2)
	{
		ft_printf("Error\nWrong amount of arguments!\n");
		return (0);
	}
	game_data = (t_game *) malloc(sizeof(t_game));
	if (!game_data)
		return (0);
	map = get_map(argv[1], game_data);
	if (!map)
	{
		free(game_data);
		ft_printf("Error\nMisconfigured map\n");
		return (0);
	}
	if (!game_data)
		return (0);
	load_game(game_data);
	mlx_loop(game_data->mlx);
}

void	load_game(t_game *game_data)
{
	srand(time(0));
	game_data->mlx = mlx_init();
	game_data->win = mlx_new_window(game_data->mlx,
			game_data->width * TILE_SIZE,
			game_data->height * TILE_SIZE, "Dolphin goes brrr");
	load_enemies(game_data);
	register_hooks(game_data);
	load_imgs(game_data);
	paint_map(game_data);
	game_data->moves = 0;
	time(&(game_data->start_time));
}
