/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:19:51 by weyap             #+#    #+#             */
/*   Updated: 2025/06/19 09:19:51 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_nullstr(t_properties *properties, char *str);

int	ft_printstr(t_properties *properties, char *str)
{
	int		width;
	int		str_len;
	int		padding;

	width = properties->field_width;
	if (!str)
		str = get_nullstr(properties, str);
	str_len = (int)ft_strlen(str);
	if (properties->flags & HAS_PRECISION && properties->precision < str_len)
		str_len = properties->precision;
	if (str_len > width)
		width = str_len;
	padding = width - str_len;
	if (!(properties->flags & LEFT_ALIGN))
		ft_printpadding(padding, ' ');
	while (str_len--)
		ft_putchar_fd(*str++, STDOUT_FILENO);
	if (properties->flags & LEFT_ALIGN)
		ft_printpadding(padding, ' ');
	return (width);
}

static char	*get_nullstr(t_properties *properties, char *str)
{
	if (!(properties->flags & HAS_PRECISION)
		|| properties->precision >= (int)ft_strlen(NULL_STRING))
		str = NULL_STRING;
	else
		str = "";
	return (str);
}
