/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigde-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:25:53 by vigde-ol          #+#    #+#             */
/*   Updated: 2024/10/24 17:26:25 by vigde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//ft_putstr_fd("-2147483648", fd); Trata o caso especial do menor int
//ft_putchar_fd('-', fd); Imprime o sinal de negativo
//ft_putnbr_fd(n / 10, fd); Chama recursivamente para imprimir o resto
//ft_putchar_fd((n % 10) + '0', fd); Imprime o último dígito
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd); //recursiva
	ft_putchar_fd((n % 10) + '0', fd);
}
