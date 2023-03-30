/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:53 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/30 13:10:48 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t		ft_strlenz(char *str);
int			ft_strchrz(char c, char *buf);
void		clean(char *buf);
char		*ft_strjoinz(char *text, char *buf);
char		*get_next_line(int fd);

#endif