/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostr_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:16:01 by weyap             #+#    #+#             */
/*   Updated: 2025/06/29 21:16:01 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

char	*ft_tostr_char(char c)
{
	char	*str;

	str = (char *)ft_calloc(2, sizeof(char));
	str[0] = c;
	return (str);
}
