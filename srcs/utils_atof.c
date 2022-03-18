/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:09:47 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/14 16:09:49 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_space(char c)
{
	if (c == '\f' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_sign(char c)
{
	if (c == '+' || c <= '-')
		return (1);
	else
		return (0);
}
