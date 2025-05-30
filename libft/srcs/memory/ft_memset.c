/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:41:09 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 05:27:34 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_memset - fill a number of bytes in memory with a constant byte
 *
 *	parameters
 *		s - the memory area to fill
 *		c - the byte to fill `s` with
 *		n - the number of bytes in `s` to fill with `c`
 *
 *	variables
 *		t_s - an unsigned char pointer casted copy of `s`
 *
 *	return
 *		the filled `s`
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*t_s;

	t_s = (unsigned char *) s;
	while (n--)
		*t_s++ = c;
	return (s);
}
