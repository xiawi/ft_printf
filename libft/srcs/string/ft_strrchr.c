/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:43:53 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 08:43:53 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strrchr - locate the last occurrence of character in string
 *
 *	parameters
 * 		s - the string to be searched
 * 		c - the character to be located
 *
 *	variables
 * 		index - a number corresponding to the index of a character in `s`
 *
 * 	function calls
 * 		ft_strlen - to calculates the length of `s`
 *
 *	return
 * 		address of the last occurrence of `c` in `s` if found, otherwise NULL
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if (!c)
		return ((char *)&s[index]);
	while (index--)
		if (s[index] == (char)c)
			return ((char *)&s[index]);
	return (NULL);
}
