/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:41:05 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/30 13:08:44 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_characters(char **map)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (map[++i])
		size++;
	if (size < 3)
		return (0);
	if (!is_horizontal_wall(map[0]) || !is_horizontal_wall(map[size - 1])
		|| !check_vertical_walls(map) || !check_components(map))
		return (0);
	return (1);
}

int	check_components(char **map)
{
	int	exit;
	int	collectible;
	int	start;
	int	i;

	exit = 0;
	collectible = 0;
	start = 0;
	while (*map)
	{
		i = -1;
		while ((*map)[++i])
		{
			if ((*map)[i] == 'C')
				collectible++;
			else if ((*map)[i] == 'E')
				exit++;
			else if ((*map)[i] == 'P')
				start++;
			else if ((*map)[i] != '1' && (*map)[i] != '0' && (*map)[i] != 'S')
				return (0);
		}
		map++;
	}
	return (exit >= 1 && collectible >= 1 && start == 1);
}

int	check_vertical_walls(char **map)
{
	size_t		len;

	if (!map || !(*map))
		return (0);
	len = ft_strlen(*map);
	while (*map)
	{
		if ((*map)[0] != '1' || (*map)[len - 1] != '1')
			return (0);
		map++;
	}
	return (1);
}

int	is_horizontal_wall(char *line)
{
	size_t		i;
	size_t		size;

	size = ft_strlen(line);
	i = 0;
	while (line[i] && line[i] == '1')
		i++;
	return (i == size);
}

int	is_rectangular(char **map)
{
	size_t	len;

	if (!map || !(*map))
		return (0);
	len = ft_strlen(*map++);
	while (*map)
	{
		if (map + 1 == NULL && ft_strlen(*map++) == len)
			return (0);
		if (ft_strlen(*map++) != len)
			return (0);
	}
	return (1);
}
