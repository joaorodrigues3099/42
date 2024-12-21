#ifndef MEMLIB_H
#define MEMLIB_H

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_matrix(void **matrix, int index);
void	*ft_realloc(void *src, size_t old_size, size_t new_size);
void	*ft_dup_data(void *data, int type);
int		ft_abs(int i);

#endif //MEMLIB_H
