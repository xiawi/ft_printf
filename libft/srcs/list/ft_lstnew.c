/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:02:36 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:10:06 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstnew - creates a new linked list node
 *
 *	parameters
 *		content - the content to place in the node
 *
 *	variables
 *		node - the node to return
 *
 *	function calls
 *		malloc - allocates memory from the heap
 *
 *	return
 *		`node`
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
