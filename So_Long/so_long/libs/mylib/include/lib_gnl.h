/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_gnl.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:19:34 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/08 17:58:27 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GNL_H
# define LIB_GNL_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1069
# endif

# ifndef FD_MAX
#  define FD_MAX 69
# endif

char	*ft_gnl_strchr(const char *str, char c);
size_t	ft_gnl_strlen(const char *str);
void	*ft_gnl_calloc(size_t nmemb, size_t size);
char	*ft_gnl_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);

#endif // LIB_GNL_H
