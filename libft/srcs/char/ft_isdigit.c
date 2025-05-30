/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:40:32 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 08:40:32 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_isdigit - checks if a character passed in is a digit
 *
 *	parameters
 *		c - the character to be checked
 *
 *	return
 *		returns a boolean value
 *			1 - if `c` is a digit
 *			0 - otherwise
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
