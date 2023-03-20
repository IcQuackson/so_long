/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:54:31 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/10 17:03:23 by quackson         ###   ########.fr       */
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


int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}


/* int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	t_data	img;

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

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int i = 0;
	printf("\n");
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	free_map(map);
} */