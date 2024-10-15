/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:04:55 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 18:38:09 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (!lst || !(*lst) || !del)
		return ;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
