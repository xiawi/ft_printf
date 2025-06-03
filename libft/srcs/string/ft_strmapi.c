/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:53:18 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 16:53:18 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strmapi - duplicates a string and applies a function to each character
 *				 in the string
 *
 *	parameters
 *		s - string to be duplicated
 *		f - function to be applied to each character in `s`
 *
 *	variables
 *		str - dynamically allocated copy of `s`
 *		index - index corresponding to a character in `str`, passed as an
 *				argument for `f`
 *
 *	function calls
 *		ft_strdup - duplicates `s`
 *
 *	return
 *		`str`
 *
 *	notes
 *		[45-46]
 *			if `s` is NULL, return NULL
 *		[47-48]
 *			if `f` is NULL, we simply return an unedited duplicate of `s`
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	str = ft_strdup(s);
	if (str)
	{
		index = 0;
		while (str[index])
		{
			str[index] = f(index, str[index]);
			index++;
		}
	}
	return (str);
}
