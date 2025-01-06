/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:20:26 by ctirapo-          #+#    #+#             */
/*   Updated: 2024/07/31 23:13:08 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	exit_with_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	ft_run_map(t_map map)
{
	int	i;

	i = 0;
	ft_solve(&map);
	while (i < map.rows)
	{
		write(1, map.map[i], map.cols);
		write(1, "\n", 1);
		free(map.map[i]);
		i++;
	}
}

void	run_stdi(void)
{
	t_map	map;
	char	*buffer;

	map.valid = true;
	buffer = read_stdi(BUFFER_SIZE);
	validate_metadata(buffer, &map);
	parse_map_lines(buffer, &map);
	free(buffer);
	if (map.valid)
		ft_run_map(map);
	else
		write(1, "map error\n", 11);
	free(map.map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		j;

	j = 1;
	if (argc < 2)
		run_stdi();
	while (j < argc)
	{
		map = parse_file(argv[j], false);
		if (map.valid)
			ft_run_map(map);
		else
			write(1, "map error\n", 11);
		free(map.map);
		j++;
	}
	return (EXIT_SUCCESS);
}
