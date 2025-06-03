/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:42:21 by weyap             #+#    #+#             */
/*   Updated: 2025/05/22 18:42:21 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_putendl_fd - writes a string followed by a new line to the given file 
 *					descriptor
 *
 *	parameters
 *		s - the string to be written
 *		fd - the file descriptor to write to
 *
 *	function calls
 *		ft_putstr - writes `s` to `fd`
 *		ft_putchar - writes '\n' to `fd`
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
