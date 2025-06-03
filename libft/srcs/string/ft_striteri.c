/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:18:37 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 18:18:37 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_striteri - applies a function on each character of a string
 *
 *	parameters
 *		s - string to be modified
 *		f - function to be applied to all characters in `s`
 *
 *	variables
 *		index - index corresponding to a character in `s`, used as an argument
 *				in f
 *
 *	notes
 *		[34-35]
 *			if either s or f are NULL, nothing is done and the function returns
 *			early
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	if (!s || !f)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
