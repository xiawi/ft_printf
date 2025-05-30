/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:28:19 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 10:28:19 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_strlen - calculates the length of a string
 *
 *	parameters
 *		s - the string to calculate the length of
 *
 *	variables
 *		len - the length of `s`
 *
 *	return
 *		`len`
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
