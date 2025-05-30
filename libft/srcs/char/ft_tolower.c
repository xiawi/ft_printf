/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 08:37:39 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 08:37:39 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_tolower - convert character to lowercase
 *
 *	parameters
 * 		int	c - the unsigned char to be converted
 *
 *	return
 * 		if a lowercase representation exists, return the transformed c,
 * 		otherwise just return c.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
