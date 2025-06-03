/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:25:42 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 10:25:42 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strnstr - locate a substring in a string
 *
 *	parameters
 * 		big - the string to be searched
 * 		little - the substring to find
 * 		len - the length of characters to be searched
 *
 *	variables
 * 		little_len - length of `little`
 * 		index - number corresponding to a character's index in `big`
 *
 *	function call
 * 		ft_strlen - gets length of `little`
 * 		ft_strncmp - to check if `little` is found in `big`
 *
 *	return
 * 		a pointer to the first occurrence of `little` in `big` if available,
 * 		otherwise return NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	index;

	little_len = ft_strlen(little);
	index = 0;
	if (!*little)
		return ((char *)big);
	while (index + little_len <= len && big[index])
	{
		if (!ft_strncmp(&big[index], little, little_len))
			return ((char *)&big[index]);
		index++;
	}
	return (NULL);
}
