/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:39:29 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 11:39:29 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_memmove - safer memcpy that deals with overlapping
 *
 *	parameters
 *		dest - the memory area to be copied to
 *		src - the memory area to be copied from
 *		n - number of bytes to copy
 *
 *	notes
 *		[36-37]
 *			if dest and src share the same address, or if n is 0, we simply
 *			return dest without changing anything
 *		[38-41]
 *			if address of dest is smaller than src, we use ft_memcpy, otherwise
 *			copy src to dest backwards
 *		[40]
 *			n is decremented in line 34, this is important because the nth
 *			byte of src and dest has an index of n - 1
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
