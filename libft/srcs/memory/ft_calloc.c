/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:20:33 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 11:20:33 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_calloc - allocates dynamic memory and fills it with 0
 *
 *	parameters
 * 		nmemb - number of elements to allocate memory to
 * 		size - the size of each element
 *
 *	variables
 * 		mem - the space in memory to return to caller
 *
 *	function calls
 *		malloc - allocates space from the heap
 * 		ft_bzero - fills allocated memory with zeros
 *
 *	return
 *		a single byte of freeable memory if `nmemb` or `size` is 0, NULL if
 *		memory allocation fails, otherwise the allocated memory
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;

	if (nmemb * size == 0)
		return (malloc(1));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	mem = (unsigned char *)malloc(nmemb * size);
	if (mem)
		ft_bzero(mem, nmemb * size);
	return ((void *)mem);
}
