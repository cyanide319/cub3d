/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:26:42 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/13 20:55:39 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	new_node = new;
	while (lst->next)
	{
		lst = lst->next;
		new_node->next = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new_node = new_node->next;
	}
	return (new);
}
