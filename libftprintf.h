/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:12:12 by weyap             #+#    #+#             */
/*   Updated: 2025/06/03 15:12:12 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

// System-dependent defaults
# ifdef __APPLE__
#  define NULL_STRING ""
#  define NULL_POINTER "0x0"
# else
#  define NULL_STRING "(null)"
#  define NULL_POINTER "(nil)"
# endif

// Format parsing
# define FT_PRINTF_SPECS "cspdiuxX%"

enum	e_flags
{
	LEFT_ALIGN = 1 << 0,
	ZERO_PADDING = 1 << 1,
	HAS_PRECISION = 1 << 2,
	ALT_FORM = 1 << 3,
	SPACE_SIGN = 1 << 4,
	FORCE_SIGN = 1 << 5,
};

typedef struct s_properties
{
	char	flags;
	int		field_width;
	int		precision;
	char	specifier;
}	t_properties;

// Function typedef
typedef int	(*t_printer)(t_properties *properties, va_list args);

// Functions
// Main printf
int		ft_printf(const char *format, ...);

// Format-specific printers
int		ft_printchar(t_properties *properties, va_list args);
int		ft_printstr(t_properties *properties, va_list args);

// Helpers
void	ft_printpadding(int count, char c);

#endif
