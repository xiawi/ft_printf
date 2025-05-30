/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:45:28 by weyap             #+#    #+#             */
/*   Updated: 2025/05/30 16:45:28 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_conversion(const char specifier, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_conversion(*format++, args);
		}
		ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

static void	handle_conversion(const char specifier, va_list args)
{
	if (specifier == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (specifier == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (specifier == 'd' || specifier == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (specifier == '%')
		ft_putchar_fd('%', 1);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("testing testin%c\n%d\n%s\n%i\n%%\n", 'g', 129, "what", -69);
	printf("testing testin%c\n%d\n%s\n%i\n%%\n", 'g', 129, "what", -69);
}
