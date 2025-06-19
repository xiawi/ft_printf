/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpadding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:55:52 by weyap             #+#    #+#             */
/*   Updated: 2025/06/19 09:55:52 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printpadding(int count, char c)
{
	while (count--)
		ft_putchar_fd(c, STDOUT_FILENO);
}
