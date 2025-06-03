/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:02:46 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 09:02:46 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_memchr - scan memory for a character
 *
 *	parameters
 * 		s - the memory area to be scanned
 * 		c - the character to be searched
 * 		n - the number of bytes to search
 *
 *	variables
 * 		t_s - the unsigned char pointer casted copy of `s`
 *
 *	return
 *		address of first occurrence of `c` if found, otherwise NULL
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t_s;

	t_s = (unsigned char *)s;
	while (n--)
	{
		if (*t_s == (unsigned char)c)
			return ((void *)t_s);
		t_s++;
	}
	return (NULL);
}
