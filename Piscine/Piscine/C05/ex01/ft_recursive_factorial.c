/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:28 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/24 13:52:52 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#includes <stdio.h>
#includes <stdlib.h>*/

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (!nb || nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("input num: %d\n", atoi(argv[1]));
		printf("factorial: %d\n", ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
*/