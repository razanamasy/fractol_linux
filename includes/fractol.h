/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:10:41 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 17:36:09 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_coord {
	double	x;
	double	y;
}		t_coord;

typedef struct s_plan {
	double	width;
	double	height;
}		t_plan;

typedef struct s_vars {
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fract;
	int			shift;
	long long	zoom;
	float		zoom_deci;
	t_coord		lim1;
	t_coord		lim2;
	t_coord		c;
	t_coord		middle;
	t_plan		plan;
}			t_vars;

int		is_space(char c);
int		is_digit(char c);
int		is_sign(char c);
void	put_str(char *str);
double	ft_atof(const char *str, int *error);

void	close_window(t_vars *vars);
int		ft_strlen(char *str);
double	val_abs(double nb);
void	get_norm(double z_r, double z_i, double *norm);

void	put_to_buff(t_vars *vars, int x, int y, int color);
void	draw_point(t_coord c, t_vars *vars, int i);

void	init_mandelbrot(t_vars *vars);
int		is_mandelbrot(double c_x, double c_y, int zoom);
void	get_mandel_coordonate(t_vars *vars);

void	init_julia(t_vars *vars, char *argv[], int argc);
int		is_julia(double z_x, double z_y, int zoom, t_coord c);
void	get_julia_coordonate(t_vars *vars);

int		zoom_central(int keycode, t_vars *vars);
int		zoom(int keycode, int x, int y, t_vars *vars);
int		translate(int keycode, t_vars *vars);

#endif
