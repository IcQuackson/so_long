/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/20 13:55:52 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/mlx_int.h"
#include "../includes/so_long.h"
#include "../includes/ft_printf.h"



int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		ft_printf("Error\nNot enough arguments\n");
		return (0);
	}
	map = get_map(argv[1]);
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
	free_map(map);
	
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, key_press_event, key_press_mask, close_window_esc, &vars);
	mlx_hook(vars.win, destroy_event, key_press_mask, close_win_cross, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}