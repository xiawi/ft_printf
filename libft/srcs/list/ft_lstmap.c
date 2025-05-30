/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:11:39 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:11:39 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstmap - creates a new list by applying a function to the content of 
 *				each node in an existing list
 *
 *	parameters
 *		lst  - pointer to the first node of the original list
 *		f    - function to apply to each node’s content
 *		del  - function to delete the content of a node (used for cleanup)
 *
 *	variables
 *		new_lst - pointer to the head of the new list
 *		latest  - pointer to the most recently added node in `new_lst`
 *
 *	function calls
 *		ft_lstnew   - creates a new node using the result of `f(lst->content)`
 *		ft_lstclear - frees memory of `new_lst` if a node allocation fails
 *
 *	return
 *		new list if all allocations succeed, otherwise NULL
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*latest;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst)
	{
		latest = new_lst;
		lst = lst->next;
		while (lst)
		{
			latest->next = ft_lstnew(f(lst->content));
			if (!latest->next)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			latest = latest->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
