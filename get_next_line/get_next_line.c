/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:14:09 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/29 18:18:45 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

char	*get_next_line(int fd)
{
	static char	stash[2];
	char		*line;

	line = NULL;
	if (fd < 0)
		return (0);
	while (stash[0] || read(fd, stash, 1) > 0)
	{
		if (ft_strchrz('\n', stash))
		{
			clean(stash);
			break ;
		}
		line = ft_strjoinz(line, stash);
		clean(stash);
	}
	return (line);
}
