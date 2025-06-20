/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:34:34 by weyap             #+#    #+#             */
/*   Updated: 2025/06/19 14:58:08 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hexlen(unsigned long pointer);
static void	puthex(unsigned long pointer);

int	ft_printptr(t_properties *properties, void *pointer)
{
	int				width;
	int				hex_len;
	int				padding;

	if (!pointer)
	{
		ft_putstr_fd(NULL_POINTER, STDOUT_FILENO);
		return (ft_strlen(NULL_POINTER));
	}
	width = properties->field_width;
	hex_len = hexlen((unsigned long)pointer);
	if (hex_len + 2 > width)
		width = hex_len + 2;
	padding = width - hex_len - 2;
	if (!(properties->flags & LEFT_ALIGN)
		&& !(properties->flags & ZERO_PADDING))
		ft_printpadding(padding, ' ');
	ft_putstr_fd("0x", STDOUT_FILENO);
	if (properties->flags & ZERO_PADDING)
		ft_printpadding(padding, '0');
	puthex((unsigned long)pointer);
	if (properties->flags & LEFT_ALIGN)
		ft_printpadding(padding, ' ');
	return (width);
}

static int	hexlen(unsigned long pointer)
{
	int	len;

	len = 0;
	while (pointer)
	{
		len++;
		pointer /= 16;
	}
	return (len);
}

static void	puthex(unsigned long pointer)
{
	if (!pointer)
		return ;
	puthex(pointer / 16);
	return (ft_putchar_fd(HEX_LOWER[pointer % 16], STDOUT_FILENO));
}
