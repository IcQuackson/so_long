/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:41:57 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/20 13:56:46 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window_esc(int keycode, t_vars *vars)
{
	if (keycode == esc)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_win_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	ft_printf("Hello from key_hook! %d\n", keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void) x;
	(void) y;
	(void) vars;
	ft_printf("Hello from key_hook! %d\n", button);
	return (0);
}
