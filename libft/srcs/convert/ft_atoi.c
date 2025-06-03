/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:32:06 by weyap             #+#    #+#             */
/*   Updated: 2025/05/20 10:32:06 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_atoi - convert a string to an integer
 *	
 *	parameters
 * 		nptr - the string to be converted
 *
 *	variables
 * 		mult - multiplier that can either be 1 or -1 (if there is a - sign)
 * 		abs - the absolute value of the integer
 *
 *	function calls
 * 		ft_isdigit - check if a character is a digit
 *
 *	return
 * 		the converted integer
 */
int	ft_atoi(const char *nptr)
{
	char	mult;
	int		abs;

	mult = 1;
	abs = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			mult *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		abs = 10 * abs + *nptr - '0';
		nptr++;
	}
	return (mult * abs);
}
