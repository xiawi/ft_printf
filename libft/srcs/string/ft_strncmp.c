/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:57:44 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 08:57:44 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strncmp - compare two strings up to n bytes
 *
 *	parameters
 * 		s1, s2 - strings to be compared
 * 		n - number of bytes to check for comparison
 *
 *	return
 * 		if a difference is found, return the difference between the two
 * 		characters, else return 0.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
