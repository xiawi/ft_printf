/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:37:23 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 18:37:23 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_putstr_fd - writes a string to the given file descriptor
 *	
 *	parameters
 *		s - the string to be written
 *		fd - the file descriptor to write to
 *
 *	function calls
 *		write - system call to output bytes to a file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
