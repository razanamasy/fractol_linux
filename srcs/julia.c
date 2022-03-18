/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:10 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 16:56:33 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_vars *vars, char *argv[], int argc)
{
	int	j;

	j = 0;
	if (argc == 4)
	{
		vars->c.x = ft_atof(argv[2], &j);
		vars->c.y = ft_atof(argv[3], &j);
	}
	else
	{
		vars->c.x = 0.285;
		vars->c.y = 0.01;
	}
	vars->middle.x = 0;
	vars->middle.y = 0;
	vars->shift = 0;
	vars->lim1.x = -1.5;
	vars->lim2.x = 1.5;
	vars->lim1.y = -1.5;
	vars->lim2.y = 1.5;
	vars->zoom = 200;
	vars->fract = 0;
	vars->plan.width = 600 / 100;
	vars->plan.height = 600 / 100;
	get_julia_coordonate(vars);
}

int	is_julia(double z_x, double z_y, int zoom, t_coord c)
{
	double	z_rtmp;
	double	z_norm;
	int		n;
	int		n_max;

	(void)zoom;
	z_rtmp = z_x;
	n = 0;
	n_max = 150;
	z_norm = 0;
	while (n < n_max && z_norm < 4)
	{
		z_x = z_x * z_x - z_y * z_y + c.x;
		z_y = 2 * z_y * z_rtmp + c.y;
		get_norm(z_x, z_y, &z_norm);
		z_rtmp = z_x;
		n++;
	}
	return (n);
}

void	get_julia_coordonate(t_vars *vars)
{
	int		i;
	t_plan	n_image;
	t_coord	z;
	t_coord	zplan;

	i = 0;
	z.x = 0;
	z.y = 0;
	n_image.width = vars->lim2.x - vars->lim1.x;
	n_image.height = vars->lim2.y - vars->lim1.y;
	while (z.x < 600)
	{
		z.y = 0;
		while (z.y < 600)
		{
			zplan.x = ((z.x * n_image.width) / 600) + vars->lim1.x;
			zplan.y = ((z.y * n_image.height) / 600) + vars->lim1.y;
			i = is_julia(zplan.x, zplan.y, vars->zoom / 100, vars->c);
			draw_point(z, vars, i);
			z.y += 1;
		}
		z.x += 1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
