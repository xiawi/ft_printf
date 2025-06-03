/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 08:57:06 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 08:57:06 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strtrim - trims characters off the start and end of a string
 *
 *	parameters
 *		s1 - the string to be edited
 *		set - the character set to be trimmed off
 *
 *	variables
 *		start - the start index of the substring
 *		len - the length of the substring
 *
 *	function calls
 *		ft_strdup - duplicates `s1` if NULL is passed in as `set`
 *		ft_strchr - checks if a character is in `set`
 *		ft_strlen - calculates the length of `s1`
 *		ft_substr - creates the desired substring to return
 *
 *	return
 *		a freeable copy of the string with characters trimmed off from start
 *		and end
 *
 *	notes
 *		[47-48]
 *			if `s1` is NULL, we just return NULL
 *		[49-50]
 *			if `set` is NULL, we simply return a freeable copy of `s1`
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1) - start;
	while (ft_strchr(set, s1[start + len - 1]))
		len--;
	return (ft_substr(s1, start, len));
}
