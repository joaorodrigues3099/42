/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:01 by joao-alm          #+#    #+#             */
/*   Updated: 2025/02/08 18:02:46 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int pid;

	(void)ac;
	(void)av;
	printf("I'm the parent\n");
	for (int i = 0; i < 4; ++i)
	{
		if (!pid)
		{
			pid = fork();
			if (pid)
				printf("I'm the child %d\n", i);
		}
	}
	return (0);
}
