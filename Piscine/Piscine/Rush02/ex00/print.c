/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:02 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 23:44:03 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_value(char *str)
{
	char *value;
		
	value = find_value_by_key(read_file(g_dictionary), str);
	write(1, value + 1, ft_strlen(value));
}

void	ft_ones(char *buffer)
{
	char	ones_buf[2];

	ones_buf[0] = buffer[0];
	ones_buf[1] = '\0';
	ft_print_value(ones_buf);
}

void	ft_tens(char *buffer)
{
	char	tens_buf[3];

	tens_buf[0] = buffer[0];
	tens_buf[1] = buffer[1];
	tens_buf[2] = '\0';
	if (tens_buf[0] < '2' || tens_buf[1] == '0')
	{
		ft_print_value(tens_buf);
		if (buffer[2] != '\0')
			ft_putstr(" ");
	}
	else
	{
		tens_buf[0] = buffer[0];
		tens_buf[1] = '0';
		ft_print_value(tens_buf);
		ft_putstr("-");
		tens_buf[0] = buffer[1];
		tens_buf[1] = '\0';
		ft_print_value(tens_buf);
		if (buffer[2] != '\0')
			ft_putstr(" ");
	}
}

void	ft_hundreds(char *buffer)
{
	char	hundreds_buf[4];

	hundreds_buf[0] = buffer[0];
	hundreds_buf[1] = '\0';
	ft_print_value(hundreds_buf);
	ft_putstr(" ");
	ft_print_value("100");
	if (ft_checkzeros(buffer))
		ft_putstr(" ");
	hundreds_buf[1] = buffer[1];
	hundreds_buf[2] = buffer[2];
	if (hundreds_buf[1] != '0')
	{
		ft_putstr(" and ");
		ft_tens(buffer + 1);
	}
	if (hundreds_buf[1] == '0' && hundreds_buf[2] != '0')
	{
		ft_putstr(" and ");
		ft_ones(buffer + 2);
	}
}

void	ft_print_block(char *buffer, int n_in_block)
{
	int	i;

	i = 0;
	if (n_in_block > 1)
	{
		while (i < 3 && *buffer == '0') //skip 0's
		{	
			i++;
			buffer++;
			n_in_block--;
		}
	}
	if (n_in_block == 1)
	{
		ft_ones(buffer);
		if (buffer[1] != '\0')
			ft_putstr(" ");
	}	
	if (n_in_block == 2)
	{
		ft_tens(buffer);
	}
	if (n_in_block == 3)
	{
		ft_hundreds(buffer);
	}
}