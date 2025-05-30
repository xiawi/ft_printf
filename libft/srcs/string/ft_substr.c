/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:12:05 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 07:12:05 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_substr - creates a substring from a string
 *
 *	parameters
 * 		s - the string from which the substring will be created
 * 		start - the start index of the substring in s
 * 		len - the maximum length of the substring
 *
 *	variables
 * 		substr - the substring
 * 		size - size of allocated memory space
 *
 *	function calls
 *		ft_strlen -	to calculate the lengths of `s` from its starting index, as
 *					well as from index `start`
 *		ft_calloc -	to return an empty string if `start` is greater than the
 *					length of s
 * 		malloc - allocates space from the heap
 *		ft_strlcpy - copies `size` characters from `s` at index `start` to
 *					 `substr`
 *
 *	return
 *		returns `substr` on success, otherwise return NULL.
 *
 *	notes
 * 		[55-56]
 * 			if `start` is greater than the length of `s`, we simply return a
 * 			freeable empty string
 *		[57-60]
 * 			if length goes beyond the bounds of the string, we allocate only
 * 			the length of the string from index `start` + 1 (for the NUL
 * 			terminator), otherwise len + 1
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(&s[start]) > len)
		size = len + 1;
	else
		size = ft_strlen(&s[start]) + 1;
	substr = (char *)malloc(sizeof(char) * (size));
	if (substr)
		ft_strlcpy(substr, &s[start], size);
	return (substr);
}
