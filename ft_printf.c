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
	static char	flag_bitmask[128];
	static char	initialized;

	if (!initialized)
	{
		flag_bitmask['-'] = LEFT_ALIGN;
		flag_bitmask['0'] = ZERO_PADDING;
		flag_bitmask['#'] = ALT_FORM;
		flag_bitmask[' '] = SPACE_SIGN;
		flag_bitmask['+'] = FORCE_SIGN;
		initialized = 1;
	}
	while (flag_bitmask[(unsigned char)**format])
	{
		properties->flags |= flag_bitmask[(unsigned char)**format];
		(*format)++;
	}
}

static int	dispatch_printer(t_properties *properties, va_list args)
{
	static t_printer	printers[128];
	static char			initialized;
	t_printer			fn;

	if (!initialized)
	{
		printers['c'] = &ft_printchar;
//		printers['s'] = &ft_printstr;
//		printers['p'] = &ft_printptr;
//		printers['d'] = &ft_printint;
//		printers['i'] = &ft_printint;
//		printers['u'] = &ft_printuint;
//		printers['x'] = &ft_printhex_lower;
//		printers['X'] = &ft_printhex_upper;
//		printers['%'] = &ft_printpercent;
		initialized = 1;
	}
	fn = printers[(unsigned char)properties->specifier];
	if (!fn)
		return (-1);
	return (fn(properties, args));
}
