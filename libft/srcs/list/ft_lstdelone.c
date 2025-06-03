/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weyap <weyap@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:10:54 by weyap             #+#    #+#             */
/*   Updated: 2025/05/23 21:10:54 by weyap            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	ft_lstdelone - frees a single node
 *
 *	parameters
 *		lst - the node to free
 *		del - pointer to a function used to delete the content of the node
 *
 *	function calls
 *		free - frees dynamically allocated memory back to the heap
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
