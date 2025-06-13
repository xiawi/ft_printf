/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:56:57 by weyap             #+#    #+#             */
/*   Updated: 2025/06/05 17:56:57 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_conversion(const char **format, va_list args, int *chars);
static void	set_properties(const char **format, t_properties *properties);
static void	put_conversion(t_properties *properties, va_list args, int *chars);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars;

	va_start(args, format);
	chars= 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_conversion(&format, args, &chars);
		}
		else
		{
			ft_putchar_fd(*format++, STDOUT_FILENO);
			chars++;
		}
	}
	va_end(args);
	return (chars);
}

static void	handle_conversion(const char **format, va_list args, int *chars)
{
	t_properties	*properties;

	properties = (t_properties *)ft_calloc(sizeof(t_properties), 1);
	if (properties)
	{
		set_properties(format, properties);
		if (ft_strchr(FT_PRINTF_SPECS, properties->specifier))
			put_conversion(properties, args, chars);
		else
			*chars = -1;
		free(properties);
	}
}

static void	set_properties(const char **format, t_properties *properties)
{
	while (ft_strchr(FT_PRINTF_FLAGS, **format))
	{
		if (**format == '-')
			properties->flags |= LEFT_ALIGN;
		if (**format == '0')
			properties->flags |= ZERO_PADDING;
		if (**format == '#')
			properties->flags |= ALT_FORM;
		if (**format == ' ')
			properties->flags |= SPACE_SIGN;
		if (**format == '+')
			properties->flags |= FORCE_SIGN;
		(*format)++;
	}
	properties->field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		properties->flags |= HAS_PRECISION;
		properties->precision = ft_atoi(++(*format));
		while (ft_isdigit(**format))
			(*format)++;
	}
	properties->specifier = *((*format)++);
}

static void	put_conversion(t_properties *properties, va_list args, int *chars)
{
	if (properties->specifier == 'c')
	{
		(*chars)++;
		ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
	}
}
