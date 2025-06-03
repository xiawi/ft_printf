/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:10:41 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:10:41 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstclear - frees a whole list
 *
 *	parameters
 *		lst - the list to be freed
 *		del - pointer to a function used to delete the content of a node
 *
 *	variables
 *		prev - pointer to the previous node to be freed
 *
 *	function calls
 *		free - frees dynamically allocated memory back to the heap
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (del)
	{
		while (*lst)
		{
			prev = *lst;
			del((*lst)->content);
			*lst = (*lst)->next;
			free(prev);
		}
	}
}
