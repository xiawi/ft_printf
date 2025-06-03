/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:54:25 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 08:54:25 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_isalnum - checks if a character passed in is in the ASCII character set
 *
 *	parameters
 *		c - the character to be checked
 *
 *	return
 *		returns a boolean value
 *			1 - if `c` is in the ASCII character set
 *			0 - otherwise
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
