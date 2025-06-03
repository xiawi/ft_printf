/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:37:30 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 05:42:10 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_isalpha - checks if a character passed in is alphabetical
 *
 *	parameters
 *		c - the character to be checked
 *
 *	return
 *		returns a boolean value
 *			1 - if `c` is alphabetical
 *			0 - otherwise
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
