/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 14:47:29 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/mlx_int.h"
#include "../includes/so_long.h"
#include "../includes/ft_printf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
}