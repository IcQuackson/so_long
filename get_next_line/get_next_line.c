/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:14:09 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 11:52:28 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		n;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	n = 1;
	while (!(ft_strchr1(stash, '\n')) && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[n] = '\0';
		stash = ft_strjoin1(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	int 	fd;
	char	buffer[256];
	
	if ((fd = open("teste",O_RDONLY)) == -1)
	{
		printf("Erro a ler ficheiro \n");	
		return (-1);
	}
	char *s = get_next_line(fd);
	//assert(s == NULL);
	while (s)
	{
		printf("%ld\nstr: %s\n", strlen(s), s);
		s = get_next_line(fd);
	}
} */
