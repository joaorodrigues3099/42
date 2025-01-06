/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:20:14 by ctirapo-          #+#    #+#             */
/*   Updated: 2024/07/31 23:18:15 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
	bool	valid;
}			t_map;

typedef struct s_square
{
	int		size;
	int		x;
	int		y;
}			t_square;

// parse.c
void		parse_metadata(char *buffer, t_map *map);
void		parse_map_lines(char *ptr, t_map *map);
t_map		parse_file(const char *filename, bool stdi);
char		*read_stdi(size_t buffer_size);
# define BUFFER_SIZE 3000000
// validate.c
void		validate_unique_chars(t_map *map);
void		validate_metadata(char *buffer, t_map *map);
void		validate_map_line(char *ptr, t_map *map);
void		ft_map_error(char *str);
// solver.c
void		ft_solve(t_map *map);
// utils.c
int			ft_strlen(char *str);
char		*ft_strdup(char *src, int n);
int			ft_strcmp(const char *s1, const char *s2);
void		*my_memcpy(void *dest, const void *src, size_t n);
char		*grow_buffer(char *buffer, size_t *buffer_size,
				size_t *result_size);
// main.c
void		exit_with_error(char *message);
#endif
