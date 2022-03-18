/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:30 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 18:00:05 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_middle_mouse(t_vars *vars, int x, int y)
{
	if (vars->fract)
	{
		vars->middle.x = ((x * (vars->lim2.x
						- vars->lim1.x)) / 540) + vars->lim1.x;
		vars->middle.y = ((y * (vars->lim2.y
						- vars->lim1.y)) / 480) + vars->lim1.y;
	}
	if (!vars->fract)
	{
		vars->middle.x = ((x * (vars->lim2.x
						- vars->lim1.x)) / 600) + vars->lim1.x;
		vars->middle.y = ((y * (vars->lim2.y
						- vars->lim1.y)) / 600) + vars->lim1.y;
	}
}

static void	call_zoom_function(t_vars *vars)
{
	if (vars->fract)
		get_mandel_coordonate(vars);
	else
		get_julia_coordonate(vars);
}	

void	zoom_out(t_vars *vars, long long *real_zoom, double *small_zoom)
{
	if (vars->zoom >= 200)
	{
		if (vars->zoom == 200)
		{
			vars->zoom_deci = vars->zoom;
			*small_zoom = vars->zoom_deci / 100;
		}
		vars->zoom /= 2;
		*real_zoom = vars->zoom / 100;
		vars->lim1.x = vars->middle.x - vars->plan.width / (*real_zoom * 2);
		vars->lim2.x = vars->middle.x + vars->plan.width / (*real_zoom * 2);
		vars->lim1.y = vars->middle.y - vars->plan.height / (*real_zoom * 2);
		vars->lim2.y = vars->middle.y + vars->plan.height / (*real_zoom * 2);
		call_zoom_function(vars);
	}
	else
	{
		vars->zoom_deci /= 2;
		*small_zoom = vars->zoom_deci / 100;
		vars->lim1.x = vars->middle.x - vars->plan.width / (*small_zoom * 2);
		vars->lim2.x = vars->middle.x + vars->plan.width / (*small_zoom * 2);
		vars->lim1.y = vars->middle.y - vars->plan.height / (*small_zoom * 2);
		vars->lim2.y = vars->middle.y + vars->plan.height / (*small_zoom * 2);
		call_zoom_function(vars);
	}
}

void	zoom_in(t_vars *vars, long long *real_zoom, double *small_zoom)
{
	if (vars->zoom >= 200)
	{
		if (vars->zoom == 200)
		{
			vars->zoom_deci = vars->zoom;
			*small_zoom = vars->zoom_deci / 100;
		}
		vars->zoom *= 2;
		*real_zoom = vars->zoom / 100;
		vars->lim1.x = vars->middle.x - vars->plan.width / (*real_zoom * 4);
		vars->lim2.x = vars->middle.x + vars->plan.width / (*real_zoom * 4);
		vars->lim1.y = vars->middle.y - vars->plan.height / (*real_zoom * 4);
		vars->lim2.y = vars->middle.y + vars->plan.height / (*real_zoom * 4);
		call_zoom_function(vars);
	}
	else
	{
		vars->zoom_deci *= 2;
		*small_zoom = vars->zoom_deci / 100;
		vars->lim1.x = vars->middle.x - vars->plan.width / (*small_zoom * 4);
		vars->lim2.x = vars->middle.x + vars->plan.width / (*small_zoom * 4);
		vars->lim1.y = vars->middle.y - vars->plan.height / (*small_zoom * 4);
		vars->lim2.y = vars->middle.y + vars->plan.height / (*small_zoom * 4);
		call_zoom_function(vars);
	}
}

int	zoom(int keycode, int x, int y, t_vars *vars)
{
	long long	real_zoom;
	double		small_zoom;

	real_zoom = vars->zoom / 100;
	set_middle_mouse(vars, x, y);
	if (keycode == 5 && vars->zoom_deci > 0.000001)
		zoom_out(vars, &real_zoom, &small_zoom);
	if (keycode == 4 && vars->zoom < 7205759403792793600)
		zoom_in(vars, &real_zoom, &small_zoom);
	return (0);
}
