/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:16:27 by pedgonca          #+#    #+#             */
/*   Updated: 2023/03/06 19:24:45 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (*str)
	{
		write(1, str, 1);
		len++;
		str++;
	}
	return (len);
}
