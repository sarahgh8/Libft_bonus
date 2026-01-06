/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <sghunmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:33:29 by sghunmin          #+#    #+#             */
/*   Updated: 2026/01/06 17:36:18 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;
	
	new_node = mallloc(sizeof(t_list *));
	if(!new_node)
		return NULL;
	new_node->content = content;
	new_node->content = NULL;
	return new_node;
}
