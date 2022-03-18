/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_central.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:11:31 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 18:00:35 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_centre_mouse(t_vars *vars)
{
	if (vars->fract)
	{
		vars->middle.x = -0.75;
		vars->middle.y = 0;
	}
	if (!vars->fract)
	{
		vars->middle.x = 0;
		vars->middle.y = 0;
	}
}

static void	call_zoom_function(t_vars *vars)
{
	if (vars->fract)
		get_mandel_coordonate(vars);
	else
		get_julia_coordonate(vars);
}	

void	zoom_centre_out(t_vars *vars, long long *real_zoom, double *small_zoom)
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

void	zoom_centre_in(t_vars *vars, long long *real_zoom, double *small_zoom)
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

int	zoom_central(int keycode, t_vars *vars)
{
	long long	real_zoom;
	double		small_zoom;

	real_zoom = vars->zoom / 100;
	set_centre_mouse(vars);
	if (keycode == 65453 && vars->zoom_deci > 0.000001)
		zoom_centre_out(vars, &real_zoom, &small_zoom);
	if (keycode == 65451 && vars->zoom < 7205759403792793600)
		zoom_centre_in(vars, &real_zoom, &small_zoom);
	return (0);
}
