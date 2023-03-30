/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:29:42 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/30 13:07:18 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strchrz(char c, char *line)
{
	if (!line)
		return (0);
	while (*line)
		if (*line++ == c)
			return (1);
	return (0);
}

size_t	ft_strlenz(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	clean(char *stash)
{
	int	i;
	int	j;

	i = ft_strlenz(stash);
	j = 0;
	while (stash[i])
		stash[j++] = stash[i++];
	while (stash[j])
		stash[j++] = '\0';
}

char	*ft_strjoinz(char *line, char *buff)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_strlenz(line) + ft_strlenz(buff) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (line && line[j])
		str[i++] = line[j++];
	j = 0;
	while (buff && buff[j])
	{
		str[i] = buff[j++];
		if (str[i++] == '\n')
			break ;
	}
	str[i] = '\0';
	free (line);
	return (str);
}
