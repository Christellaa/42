/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:39:28 by cde-sous          #+#    #+#             */
/*   Updated: 2024/05/16 10:41:11 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks for any printable character
** Returns nonzero if c is a printable character, zero otherwise
*/

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}