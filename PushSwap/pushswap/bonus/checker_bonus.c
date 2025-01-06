/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:01:48 by joao-alm          #+#    #+#             */
/*   Updated: 2024/12/27 12:01:48 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "lib_write.h"

int	ft_exec_ops(t_ps *data)
{
	char	*ops_str;
	int		fd;

	fd = STDIN_FILENO;
	ops_str = get_next_line(fd);
	while (ops_str)
	{
		ft_call_op(data, ops_str);
		free(ops_str);
		ops_str = get_next_line(fd);
	}
	ft_move_bot_a_to_top(data);
	if (!ft_all_in_top_a(data) || !ft_lst_sorted(data->a_top.lst))
		return (0);
	return (1);
}

int	ft_valid_data(int ac, char **av)
{
	t_ps	data;
	t_list	*lst;
	int		size;
	int		valid;

	size = 0;
	lst = ft_get_input(av, ac, &size);
	if (!lst)
		ft_error(NULL);
	ft_init_pushswap(&data, lst, size);
	if (!lst)
		ft_error(&data);
	valid = ft_exec_ops(&data);
	ft_free_pushswap(&data);
	return (valid);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	if (ft_valid_data(ac, av))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (0);
}
