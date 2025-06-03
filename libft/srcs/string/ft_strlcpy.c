/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:54:56 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 05:27:50 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strlcpy - size-bounded string copying
 *
 *	parameters
 * 		dst - the string buffer to be copied to
 * 		src - the string to be copied from
 * 		size - size of the buffer
 *
 *	variables
 * 		index - number corresponding to the index of the dst and src strings
 *
 *	function calls
 * 		ft_strlen - to get the length of src
 *
 *	return
 * 		the length of the string the function tried to create (length of src)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size)
	{
		index = 0;
		while (index < size - 1 && src[index])
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}
