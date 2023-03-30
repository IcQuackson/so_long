/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:43:50 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/30 13:10:29 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	count_lines(char *file_name)
{
	int		fd;
	int		num_lines;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error("count_lines: Erro a ler ficheiro"));
	num_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		num_lines++;
		free(line);
	}
	close(fd);
	return (num_lines);
}

char	**get_map_from_file(char *file_name)
{
	char	**map;
	int		n_lines;
	int		fd;
	int		i;

	n_lines = count_lines(file_name);
	if (n_lines <= 0)
		return (NULL);
	map = malloc((n_lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		error("get_map: Erro a ler ficheiro");
		return (NULL);
	}
	i = -1;
	while (++i < n_lines)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**get_map(char *file_name, t_game *game_data)
{
	int		len;
	char	**map;

	len = ft_strlen(file_name);
	if (len < 5)
		return (NULL);
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (NULL);
	map = NULL;
	map = get_map_from_file(file_name);
	if (!map || !is_rectangular(map) || !check_characters(map)
		|| !path_exists(map, game_data))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map[i]);
	free(map);
}

int	error(const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (0);
}
