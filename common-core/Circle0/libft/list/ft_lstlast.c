/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:28:02 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 18:41:00 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*last_seen(t_list *lst, t_list *last)
{
	if (!lst)
		return (last);
	return (last_seen(lst->next, lst));
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (last_seen(lst->next, lst));
}
