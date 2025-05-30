/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:41:33 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 08:41:33 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_isalnum - checks if a character passed in is alphanumeric
 *
 *	parameters
 *		c - the character to be checked
 *
 *	function calls
 *		ft_isalpha - to check if `c` is alphabetical
 *		ft_isidgit - to check if `c` is a digit
 *
 *	return
 *		returns a boolean value
 *			1 - if `c` is alphanumeric
 *			0 - otherwise
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
