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

static char	*getnullstr(t_properties *properties, char *str);

int	ft_printstr(t_properties *properties, va_list args)
{
	char	*str;
	size_t	str_len;
	int		padding;

	str = va_arg(args, char *);
	if (!str)
		str = getnullstr(properties, str);
	str_len = ft_strlen(str);
	if (properties->flags & HAS_PRECISION)
		if (properties->precision < str_len)
			str_len = properties->precision;
	if (str_len > properties->field_width)
		properties->field_width = str_len;
	padding = properties->field_width - str_len;
	if (!(properties->flags & LEFT_ALIGN))
		ft_printpadding(padding, ' ');
	while (str_len--)
		ft_putchar_fd(*str++, STDOUT_FILENO);
	if (properties->flags & LEFT_ALIGN)
		ft_printpadding(padding, ' ');
	return (properties->field_width);
}

static char	*getnullstr(t_properties *properties, char *str)
{
	if (!(properties->flags & HAS_PRECISION) || properties->precision >= 6)
		str = NULL_STRING;
	else
		str = "";
	return (str);
}
