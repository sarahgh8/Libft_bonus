/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <sghunmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:38:42 by sghunmin          #+#    #+#             */
/*   Updated: 2026/01/06 19:53:09 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*head;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	temp = lst;
	head = NULL;
	while (temp)
	{
		c = f(temp->content);
		new = ft_lstnew(c);
		if (!new)
		{
			del(c);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		temp = temp->next;
	}
	return (head);
}
