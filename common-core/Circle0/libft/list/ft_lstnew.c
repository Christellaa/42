/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:08:53 by cde-sous          #+#    #+#             */
/*   Updated: 2024/10/14 18:42:15 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = malloc(sizeof(t_list));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
