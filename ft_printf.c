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

static int	dispatch_conversion(const char **format, va_list args);
static void	populate_properties(const char **format, t_properties *properties);
static void	parse_flags(const char **format, t_properties *properties);
static int	dispatch_printer(t_properties *properties, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars;
	int		chars_converted;

	va_start(args, format);
	chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			chars_converted = dispatch_conversion(&format, args);
			if (chars_converted < 0)
				return (-1);
			chars += chars_converted;
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

static int	dispatch_conversion(const char **format, va_list args)
{
	t_properties	*properties;
	int				chars;

	properties = (t_properties *)ft_calloc(1, sizeof(t_properties));
	if (!properties)
		return (-1);
	populate_properties(format, properties);
	if (!(properties->specifier))
	{
		free(properties);
		return (-1);
	}
	chars = dispatch_printer(properties, args);
	free(properties);
	return (chars);
}

static void	populate_properties(const char **format, t_properties *properties)
{
	parse_flags(format, properties);
	properties->field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		properties->flags |= HAS_PRECISION;
		(*format)++;
		properties->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_strchr(FT_PRINTF_SPECS, **format))
	{
		properties->specifier = **format;
		(*format)++;
	}
}

static void	parse_flags(const char **format, t_properties *properties)
{
	while (ft_strchr(FT_PRINTF_FLAGS, **format))
	{
		if (**format == '-')
		{
			properties->flags |= LEFT_ALIGN;
			properties->flags &= ~ZERO_PADDING;
		}
		if (**format == '0' && !(properties->flags & LEFT_ALIGN))
			properties->flags |= ZERO_PADDING;
		if (**format == '#')
			properties->flags |= ALT_FORM;
		if (**format == ' ' && !(properties->flags & FORCE_SIGN))
			properties->flags |= SPACE_SIGN;
		if (**format == '+')
		{
			properties->flags |= FORCE_SIGN;
			properties->flags &= ~SPACE_SIGN;
		}
		(*format)++;
	}
}

static int	dispatch_printer(t_properties *properties, va_list args)
{
	char	specifier;

	specifier = properties->specifier;
	if (specifier == 'c')
		return (ft_printchar(properties, va_arg(args, int)));
	if (specifier == 's')
		return (ft_printstr(properties, va_arg(args, char *)));
	if (specifier == 'p')
		return (ft_printptr(properties, va_arg(args, void *)));
	/*
	if (specifier == 'd' || specifier == 'i')
		return (ft_printint(properties, va_arg(args, int)));
	if (specifier == 'u')
		return (ft_printuint(properties, va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (ft_printhex(properties, va_arg(args, int), HEX_LOWER));
	if (specifier == 'X')
		return (ft_printhex(properties, va_arg(args, int), HEX_UPPER));
	*/
	if (specifier == '%')
	{
		ft_putchar_fd('%', STDOUT_FILENO);
		return (1);
	}
}
