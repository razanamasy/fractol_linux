/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:09:18 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 18:08:10 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	parsing_step(const char **str, int *error, int *i, int *sign)
{
	while (is_space(str[0][*i]))
		*i += 1;
	if (!(is_sign(str[0][*i]) || is_digit(str[0][*i])))
	{
		*error = 4;
		return (0);
	}
	if (is_sign(str[0][*i]))
	{
		if (str[0][*i] == '-')
			*sign *= -1;
		*i += 1;
	}
	if (!(is_digit(str[0][*i])))
	{
		*error = 4;
		return (0);
	}
	return (1);
}

void	parsing_decimal(const char **str, int *i, double *nb)
{
	int	power;

	power = 1;
	if (str[0][*i] == '.')
		*i += 1;
	if (is_digit(str[0][*i]))
	{
		while (is_digit(str[0][*i]))
		{
			*nb += ((double)str[0][*i] - '0') / pow(10, power);
			*i += 1;
			power++;
		}
	}
}

double	ft_atof(const char *str, int *error)
{
	int		i;
	int		sign;
	double	nb;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[0] == '\0')
		*error = 4;
	if (is_digit(str[0]) && ft_strlen((char *)str) > 10)
		*error = 4;
	if (str[0] == '-' && ft_strlen((char *)str) > 11)
		*error = 4;
	parsing_step(&str, error, &i, &sign);
	while (is_digit(str[i]))
		nb = 10 * nb + (double)str[i++] - '0';
	parsing_decimal(&str, &i, &nb);
	if (str[i] != '\0')
		*error = 4;
	if (nb > 2147483647)
		*error = 4;
	if (nb < -2147483648)
		*error = 4;
	return (sign * nb);
}
