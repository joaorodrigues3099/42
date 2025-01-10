/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:33:58 by joao-alm          #+#    #+#             */
/*   Updated: 2025/01/08 18:59:57 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "lib_print.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_make_square(t_data *img, int size)
{
	for (int i = 0; i <= size; i++)
		my_mlx_pixel_put(img, i, 0, 0x00FF0000);
	for (int i = 0; i <= size; i++)
		my_mlx_pixel_put(img, i, size, 0x00FF0000);
	for (int i = 0; i <= size; i++)
		my_mlx_pixel_put(img, 0, i, 0x00FF0000);
	for (int i = 0; i <= size; i++)
		my_mlx_pixel_put(img, size, i, 0x00FF0000);
}

int	ft_press_esc(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	ft_press_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_make_square(&img, 10);
	ft_make_square(&img, 50);
	ft_make_square(&img, 100);
	ft_make_square(&img, 200);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 500/2-25, 500/2-25);
	mlx_hook(vars.win, 2, 1L<<0, ft_press_esc, &vars);
	mlx_hook(vars.win, 17, 0L, ft_press_x, &vars);
	mlx_loop(vars.mlx);
}
