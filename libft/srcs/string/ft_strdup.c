/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:56:46 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 11:56:46 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strdup - duplicate a string
 *
 *	parameters
 * 		s - the string to duplicate
 *
 *	variables
 * 		size - size of allocated memory
 * 		copy - the duplicated string
 *
 *	function calls
 * 		ft_strlen - calculates the length of `s`
 *		malloc - allocates space from the heap
 * 		ft_strlcpy - copies `s` to `copy`
 *
 *	return
 * 		`copy`
 */
char	*ft_strdup(const char *s)
{
	int		size;
	char	*copy;

	size = ft_strlen(s) + 1;
	copy = (char *)malloc(sizeof(char) * size);
	if (copy)
		ft_strlcpy(copy, s, size);
	return (copy);
}
