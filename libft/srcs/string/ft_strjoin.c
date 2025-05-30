/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:56:55 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 07:56:55 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strjoin - joins two strings
 *
 *	parameters
 *		s1, s2 - the strings to be joined
 *
 *	variables
 *		size - the size of the string
 *		str - the string to return
 *
 *	function calls
 *		ft_strlen - gets length of both `s1` and `s2`
 * 		malloc - allocates space from the heap
 *		ft_strlcpy - copies `s1` to `str`
 *		ft_strlcat - concatenates `s2` to `str`
 *
 *	return
 *		the joined string during allocation success, otherwise NULL
 *
 *	notes
 *		[46-47]
 *			if both s1 and s2 ceases to exist, we simply return NULL
 *		[48-51]
 *			if only one of them don't exist, we just return a duplicate of the 
 *			other
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str)
	{
		ft_strlcpy(str, s1, size);
		ft_strlcat(str, s2, size);
	}
	return (str);
}
