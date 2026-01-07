/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <sghunmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 19:09:33 by sghunmin          #+#    #+#             */
/*   Updated: 2026/01/06 19:23:53 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_addr;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		del(temp->content);
		temp_addr = temp->next;
		free(temp);
		temp = temp_addr;
	}
	*lst = NULL;
}
