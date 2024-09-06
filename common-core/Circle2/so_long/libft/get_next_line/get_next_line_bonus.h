/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-sous <cde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:52:34 by cde-sous          #+#    #+#             */
/*   Updated: 2024/09/06 20:59:49 by cde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char		*ft_strnjoin_free_s1(char *s1, char const *s2, size_t len);
char		*get_next_line(int fd);

#endif
