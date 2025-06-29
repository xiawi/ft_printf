/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:30:00 by weyap             #+#    #+#             */
/*   Updated: 2025/06/29 12:30:00 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_H
# define FT_PRINTF_INTERNALS_H
# include "libft.h"

# ifdef __APPLE__
#  define NULL_STR ""
#  define NULL_PTR "0X0"
# else
#  define NULL_STR "(null)"
#  define NULL_PTR "(nil)"
# endif

# define PRINTF_FLAGS "-0# +"
# define PRINTF_SPECS "cspdiuxX%"

enum	e_flags
{
	LEFT_JUSTIFY = 1 << 0,
	ZERO_PADDING = 1 << 1,
	ALT_FORM = 1 << 2,
	SPACE_SIGN = 1 << 3,
	FORCE_SIGN = 1 << 4
};

typedef struct s_printf_info
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			specifier;
}	t_printf_info;

typedef struct s_render
{
	int		left_pad;
	char	sign;
	char	*prefix;
	int		zero_pad;
	char	*value;
	int		right_pad;
}	t_render;

char	*ft_tostr_char(char c);

#endif
