/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 20:22:29 by weyap             #+#    #+#             */
/*   Updated: 2025/06/29 20:22:29 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internals.h"
#include <unistd.h>

static int	handle_conversion(const char **format, va_list args);
static void	parse_flags(t_printf_info *info, const char **format);

/*
 *	ft_printf - formatted output conversion
 *
 *	parameters
 *		format	- the format string to be parsed and printed
 *
 *	variables
 *		args			- variable argument list containing values to format
 *		total_written	- total number of bytes written to STDOUT
 *		written_now		- number of bytes written by the current conversion
 *
 *	function calls
 *		va_start		- initializes the variable argument list `args`
 *		handle_conversion	- processes a format specifier after '%'
 *		va_end			- cleans up the variable argument list `args`
 *	
 *	return
 *		-1 if an error occurs, otherwise the total number of bytes written
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_written;
	int		written_now;

	va_start(args, format);
	total_written = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			written_now = handle_conversion(&format, args);
			if (written_now == -1)
			{
				va_end(args);
				return (-1);
			}
			total_written += written_now;
		}
		else
			total_written += write(STDOUT_FILENO, format++, 1);
	}
	va_end(args);
	return (total_written);
}

/*
 *	handle_conversion - processes a format specifier and handles conversion
 *
 *	parameters
 *		format	- a pointer to the same format string to be parsed
 *		args	- variable argument list containing values to format
 *
 *	variables
 *		info	- the printf info struct to be parsed to
 *
 *	return
 *		-1 if an error occurs, the length of the conversion otherwise
 */
static int	handle_conversion(const char **format, va_list args)
{
	t_printf_info	info;

	ft_bzero(&info, sizeof(t_printf_info));
	info.precision = -1;
	parse_flags(&info, format);
	info.width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		(*format)++;
		info.precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		if (info.precision >= 0)
			info.flags &= ~ZERO_PADDING;
	}
	if (ft_strchr(PRINTF_SPECS, **format))
		info.specifier = **format;
	else
		return (-1);
	(*format)++;
	return (0);
}

/*
 *	parse_flags - fills up the flags member of the info struct
 *
 *	parameters
 *		info	- the struct that we will parse the flags to
 *		format	- the format string to be parsed
 */
static void	parse_flags(t_printf_info *info, const char **format)
{
	while (ft_strchr(PRINTF_FLAGS, **format))
	{
		if (**format == '-')
		{
			info->flags |= LEFT_JUSTIFY;
			info->flags &= ~ZERO_PADDING;
		}
		if (**format == '0' && !(info->flags & LEFT_JUSTIFY))
			info->flags |= ZERO_PADDING;
		if (**format == '#')
			info->flags |= ALT_FORM;
		if (**format == ' ' && !(info->flags & FORCE_SIGN))
			info->flags |= SPACE_SIGN;
		if (**format == '+')
		{
			info->flags |= FORCE_SIGN;
			info->flags &= ~SPACE_SIGN;
		}
		(*format)++;
	}
}
