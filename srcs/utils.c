/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:11:19 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 16:11:21 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_str(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
}

double	val_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

void	get_norm(double z_r, double z_i, double *norm)
{
	*norm = (z_r * z_r) + (z_i * z_i);
}
