/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:10:36 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:10:36 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstadd_back - adds a node to the back of a linked list
 *
 *	parameters
 *		lst - the list to be appended to
 *		new - the new node to be appended to `lst`
 *
 *	variables
 *		last - the last node of the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
