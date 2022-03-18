/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:56 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 16:55:46 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(t_vars *vars)
{
	vars->middle.x = -0.75;
	vars->middle.y = 0;
	vars->shift = 0;
	vars->lim1.x = -2.1;
	vars->lim2.x = 0.6;
	vars->lim1.y = -1.2;
	vars->lim2.y = 1.2;
	vars->zoom = 200;
	vars->fract = 1;
	vars->plan.width = 540 / 100;
	vars->plan.height = 480 / 100;
	get_mandel_coordonate(vars);
}

int	is_mandelbrot(double c_x, double c_y, int zoom)
{
	int		n;
	int		n_max;
	t_coord	z;
	double	z_rtmp;
	double	z_norm;

	(void)zoom;
	z.x = 0;
	z.y = 0;
	z_rtmp = z.x;
	n = 0;
	n_max = 150;
	z_norm = 0;
	while (n < n_max && z_norm < 4)
	{
		z.x = z.x * z.x - z.y * z.y + c_x;
		z.y = 2 * z.y * z_rtmp + c_y;
		get_norm(z.x, z.y, &z_norm);
		z_rtmp = z.x;
		n++;
	}
	return (n);
}

void	get_mandel_coordonate(t_vars *vars)
{
	int		i;
	t_coord	c;
	t_coord	cplan;
	t_plan	n_image;

	i = 0;
	n_image.width = vars->lim2.x - vars->lim1.x;
	n_image.height = vars->lim2.y - vars->lim1.y;
	c.x = 0;
	c.y = 0;
	while (c.x < 540)
	{
		c.y = 0;
		while (c.y < 480)
		{
			cplan.x = ((c.x * n_image.width) / 540) + vars->lim1.x;
			cplan.y = ((c.y * n_image.height) / 480) + vars->lim1.y;
			i = is_mandelbrot(cplan.x, cplan.y, vars->zoom / 100);
			draw_point(c, vars, i);
			c.y += 1;
		}
		c.x += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
