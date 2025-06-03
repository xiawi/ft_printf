/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:22:34 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 10:22:34 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_memcmp - compare two memory areas
 *
 *	parameters
 * 		s1, s2 - the two areas to be compared
 *		n - the number of bytes to check for comparison
 *
 *	variables
 * 		t_s1, t_s2 - the unsigned char pointer casted copies of `s1` and `s2`
 *
 *	return
 * 		if a difference is found, the difference between the two bytes in
 * 		memory, otherwise 0.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t_s1;
	const unsigned char	*t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*t_s1 != *t_s2)
			return (*t_s1 - *t_s2);
		t_s1++;
		t_s2++;
	}
	return (0);
}
