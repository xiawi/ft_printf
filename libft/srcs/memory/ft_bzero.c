/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:21:31 by weyap             #+#    #+#             */
/*   Updated: 2025/05/19 11:21:31 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_bzero - zero a byte string
 *
 *	parameters
 *		s - the byte string to be zeroed
 *		n - the number of bytes in the byte string to zero
 *
 *	function calls
 *		ft_memset - fills n bytes in s with '\0'
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
