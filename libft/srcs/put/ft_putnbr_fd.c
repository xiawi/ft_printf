/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:47:09 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 18:47:09 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_putnbr_fd - writes a number to the given file descriptor
 *
 *	parameters
 *		n - the number to be written
 *		fd - the file descriptor to write to
 *
 *	variables
 *		str - character buffer used to build the number as a string
 *		index - number corresponding to the index of a character in `str`
 *		t_n - long casted copy of `n`
 *
 *	function calls
 *		ft_putstr_fd - writes the resulting string in the buffer 
 *
 *	notes
 *		works entirely like ft_itoa, except instead of duplicating the string,
 *		it is written to the given file descriptor
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		index;
	long	t_n;

	str[11] = '\0';
	if (!n)
	{
		str[10] = '0';
		return (ft_putstr_fd(&str[10], fd));
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
	return (ft_putstr_fd(&str[index + 1], fd));
}
