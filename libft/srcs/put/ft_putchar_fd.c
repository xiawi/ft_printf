/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:34:44 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 18:34:44 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_putchar_fd - writes a single character to a given file descriptor
 *
 *	parameters
 *		c - the character to be written
 *		fd - the file descriptor to write to
 *
 *	function calls
 *		write - system call to output bytes to a file descriptor
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
