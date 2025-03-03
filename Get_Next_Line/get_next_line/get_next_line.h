/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:55:41 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/07 21:55:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1069
# endif

// get_next_line_util
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);

// get_next_line
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
