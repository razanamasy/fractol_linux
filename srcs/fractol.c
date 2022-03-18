/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:41 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 18:12:44 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_condition(int argc, t_plan *image)
{
	if (argc > 2)
		return (0);
	image->width = 540;
	image->height = 480;
	return (1);
}

int	julia_condition(int argc, char *argv[], int *_error, t_plan *image)
{
	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 4)
	{
		ft_atof(argv[2], _error);
		ft_atof(argv[3], _error);
		if (*_error == 4)
			return (0);
	}
	image->width = 600;
	image->height = 600;
	return (1);
}

int	init_size(t_plan *image, char *argv[], int argc)
{
	int	_error;

	_error = 0;
	if (argc < 2)
		return (0);
	if (argv[1][0] == 'M')
	{
		if (!mandelbrot_condition(argc, image))
			return (0);
	}
	else if (argv[1][0] == 'J')
	{
		if (!julia_condition(argc, argv, &_error, image))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_plan	image;

	if (!init_size(&image, argv, argc))
	{
		put_str("Here's the different options :\n");
		put_str("./fractol J x y (-2147483647< x et y <2147483647)\n");
		put_str("./fractol J\n./fractol M\n");
		put_str("space bar to shift color\n");
		return (0);
	}
	init_size(&image, argv, argc);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, image.width, image.height, "Hina");
	vars.img = mlx_new_image(vars.mlx, image.width, image.height);
	vars.addr = mlx_get_data_addr(vars.img,
			&vars.bits_per_pixel, &vars.line_length, &vars.endian);
	if (argv[1][0] == 'M')
		init_mandelbrot(&vars);
	if (argv[1][0] == 'J')
		init_julia(&vars, argv, argc);
	mlx_mouse_hook(vars.win, zoom, &vars);
	mlx_key_hook(vars.win, translate, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
