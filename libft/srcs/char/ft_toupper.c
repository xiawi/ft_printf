/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:01:04 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 08:01:04 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_toupper - convert character to uppercase
 *
 *	parameters
 * 		int	c - the unsigned char to be converted
 *
 *	return
 * 		if an uppercase representation exists, return the transformed c,
 * 		otherwise just return c.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
