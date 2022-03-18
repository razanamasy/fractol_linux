/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:09:34 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 16:58:00 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_to_buff(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_point(t_coord c, t_vars *vars, int i)
{
	int	it_max;

	it_max = 150;
	if (i != it_max)
		put_to_buff(vars, c.x, c.y, (i * 0xE027FA / 150) + i + vars->shift);
	else
		put_to_buff(vars, c.x, c.y, 0xE027FA / i + i / 4 + vars->shift);
}
