/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:25:26 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 13:25:26 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_itoa - converts an integer to a string
 *
 *	parameters
 *		n - the integer to be converted
 *
 *	variables
 *		str - character buffer used to build the number as a string
 *		index - number corresponding to the index of a character in `str`
 *		t_n - long casted copy of `n`
 *
 *	function calls
 *		ft_strdup - duplicates the resulting string in the buffer
 *
 *	return
 *		a freeable string representing the integer
 *
 *	notes
 *		[51-55]
 *			if `n` is 0, simply write 0 at `index` 10 and duplicate that
 *		[56-58, 65]
 *			`t_n` helps to deal with INT_MIN, as we multiply any negative
 *			integer with a positive. Having a copy of `n` also lets us do
 *			whatever we want with `t_n`, and having the negative check at
 *			the very end of the function
 *		[67]
 *			we duplicate from `index` + 1, since index decrements at every
 *			iteration
 */
char	*ft_itoa(int n)
{
	char	str[12];
	int		index;
	long	t_n;

	str[11] = '\0';
	if (!n)
	{
		str[10] = '0';
		return (ft_strdup(&str[10]));
	}
	t_n = (long)n;
	if (t_n < 0)
		t_n *= -1;
	index = 10;
	while (t_n)
	{
		str[index--] = t_n % 10 + '0';
		t_n /= 10;
	}
	if (n < 0)
		str[index--] = '-';
	return (ft_strdup(&str[index + 1]));
}
