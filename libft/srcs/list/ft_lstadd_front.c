/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:10:21 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:10:20 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstadd_front - prepends a node to the front of the list
 *
 *	parameters
 *		lst - the list to prepend to
 *		new - the node to prepend to `lst`
 *
 *	notes
 *		[31]
 *			it is important that head of `lst` is updated to `new`
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}
