/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:41:48 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 08:41:48 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strchr - locate first occurrence of character in string
 *
 *	parameters
 * 		s - the string to be searched
 * 		c - the character to be located
 *
 *	variables
 * 		index - the number corresponding to an index in `s`
 * 		s_len - length of `s`
 *
 *	function calls
 *		ft_strlen - to calculate the length of `s`
 *
 *	return
 * 		address of the first occurrence of `c` in `s` if found, otherwise `s`'
 * 		terminating null byte.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	s_len;

	index = 0;
	s_len = ft_strlen(s);
	if (!c)
		return ((char *)&s[s_len]);
	while (index < s_len)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
