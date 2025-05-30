/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:33:19 by weyap             #+#    #+#             */
/*   Updated: 2025/05/25 16:50:46 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_memcpy - copy memory area
 *
 *	parameters
 *		dest - the memory area to be copied to
 *		src - the memory area to be copied from
 *		n - the number of bytes to copy
 *
 *	variables
 *		index - number corresponding to the index of both `src` and `dest`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dest);
}
