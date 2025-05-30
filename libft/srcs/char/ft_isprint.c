/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:42:52 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 09:42:52 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_isprint - checks if a character passed in is printable
 *
 *	parameters
 *		c - the character to be checked
 *
 *	return
 *		returns a boolean value
 *			1 - if `c` is printable
 *			0 - otherwise
 */
int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
