/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:22 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/17 11:34:03 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	call_function(t_vars *vars, int x, int y)
{
	if (vars->fract)
	{
		vars->middle.x = ((x * (vars->lim2.x
						- vars->lim1.x)) / 540) + vars->lim1.x;
		get_mandel_coordonate(vars);
	}
	else
	{
		vars->middle.x = ((y * (vars->lim2.y
						- vars->lim1.y)) / 600) + vars->lim1.y;
		get_julia_coordonate(vars);
	}
}	

void	translate_x(int keycode, t_vars *vars, int x, int y)
{
	double	trans;
	double	real_zoom;

	trans = 1.0;
	real_zoom = vars->zoom / 100;
	if (keycode == 65361)
	{
		vars->lim1.x -= trans / (real_zoom / 2);
		vars->lim2.x -= trans / (real_zoom / 2);
		call_function(vars, x, y);
	}
	else if (keycode == 65363)
	{
		vars->lim1.x += trans / (real_zoom / 2);
		vars->lim2.x += trans / (real_zoom / 2);
		call_function(vars, x, y);
	}
}

void	translate_y(int keycode, t_vars *vars, int x, int y)
{
	double	trans;
	double	real_zoom;

	trans = 1.0;
	real_zoom = vars->zoom / 100;
	if (keycode == 65362)
	{
		vars->lim1.y -= trans / (real_zoom / 2);
		vars->lim2.y -= trans / (real_zoom / 2);
		call_function(vars, x, y);
	}
	else if (keycode == 65364)
	{
		vars->lim1.y += trans / (real_zoom / 2);
		vars->lim2.y += trans / (real_zoom / 2);
		call_function(vars, x, y);
	}
}

int	translate(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	if (keycode == 65361 || keycode == 65363)
		translate_x(keycode, vars, x, y);
	else if (keycode == 65362 || keycode == 65364)
		translate_y(keycode, vars, x, y);
	else if (keycode == 65307)
		close_window(vars);
	else if (keycode == 65451 || keycode == 65453)
		zoom_central(keycode, vars);
	else if (keycode == 32)
	{
		vars->shift += 100;
		call_function(vars, x, y);
	}
	return (0);
}
