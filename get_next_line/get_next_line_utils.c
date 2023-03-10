/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:29:42 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/08 11:52:49 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!*stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_stash(char	*stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc((ft_strlen1(stash) - i + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_strchr1(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*joined;
	char	*s1_cpy;
	int		i;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	s1_cpy = s1;
	while (*s1_cpy)
		joined[i++] = *s1_cpy++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	free(s1);
	return (joined);
}

size_t	ft_strlen1(char	*s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
