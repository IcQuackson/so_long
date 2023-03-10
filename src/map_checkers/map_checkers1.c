/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:43:50 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 14:33:56 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


int	count_lines(char *file_name)
{
	int		fd;
	int		n;
	char	*s;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error("count_lines: Erro a ler ficheiro"));
	n = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		n++;
		free(s);
		s = NULL;
	}
	return (n);
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
	i = 0;
	while (i < n_lines)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	return (map);
}

char	**get_map(char *file_name)
{
	int		i;
	int		len;
	char	**map;

	len = ft_strlen(file_name);
	if (len < 5)
		return (NULL);
	i = -1;
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (NULL);
	ft_printf("file_name: %s\n", file_name);
	map = NULL;
	map = get_map_from_file(file_name);
	if (!map || !is_rectangular(map) || !check_characters(map)
		|| !path_exists(map))
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
		free(map[i++]);
	free(map[i]);
	free(map);
}

int	error(const char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (0);
}
