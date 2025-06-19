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
	int		counter;
	char	c;

	counter = 0;
	c = va_arg(args, int);
	if (!(properties->field_width))
		properties->field_width = 1;
	if (!(properties->flags & LEFT_ALIGN))
		while (counter++ < properties->field_width - 1)
			ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (properties->flags & LEFT_ALIGN)
		while (counter++ < properties->field_width - 1)
			ft_putchar_fd(' ', STDOUT_FILENO);
	return (properties->field_width);
}
