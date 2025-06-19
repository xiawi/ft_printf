/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:54:16 by weyap             #+#    #+#             */
/*   Updated: 2025/06/19 08:54:16 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printchar(t_properties *properties, va_list args)
{
	char	c;
	int		width;
	int		padding;

	c = va_arg(args, int);
	width = properties->field_width;
	if (!width)
		width = 1;
	padding = width - 1;
	if (!(properties->flags & LEFT_ALIGN))
		ft_printpadding(padding, ' ');
	ft_putchar_fd(c, STDOUT_FILENO);
	if (properties->flags & LEFT_ALIGN)
		ft_printpadding(padding, ' ');
	return (width);
}
