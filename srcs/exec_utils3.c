/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:49:28 by booi              #+#    #+#             */
/*   Updated: 2025/09/29 14:49:29 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

double	ft_power(double i, int n);
t_pt	ft_rotate(t_pt pt, double degrees);
double	ft_hypot(double x, double y);

double	ft_power(double i, int n)
{
	double	p;

	p = i;
	if (n == 0)
		return (1);
	else
	{
		while (--n > 0)
			p = i * i;
	}
	return (p);
}

t_pt	ft_rotate(t_pt pt, double degrees)
{
	t_pt	p;
	double	rad;

	pt.y = -pt.y;
	rad = mod_angle(degrees, 360) / 180 * M_PI;
	p.x = pt.x * cos(rad) - pt.y * sin(rad);
	p.y = pt.x * sin(rad) + pt.y * cos(rad);
	p.y = -p.y;
	return (p);
}

double	ft_hypot(double x, double y)
{
	return (sqrt((x * x) + (y * y)));
}
