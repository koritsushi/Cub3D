/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:51:42 by booi              #+#    #+#             */
/*   Updated: 2025/08/21 22:51:46 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

t_pt	vector_of(float angle);
int		direction_of(t_pt vector);
float	d_fisheye(t_pt pt1, t_pt pt2, float deg);
float	d_betw(t_pt pt1, t_pt pt2);
float	mod_angle(float angle, float mod);

t_pt	vector_of(float angle)
{
	t_pt	p;

	p.x = cos(angle / 180 * M_PI);
	p.y = sin(angle / 180 * M_PI) * (-1);
	return (p);
}

int	direction_of(t_pt vector)
{
	if (vector.x == 0 && vector.y == 0)
		return (HERE);
	else if (vector.x > 0 && vector.y == 0)
		return (EAST);
	else if (vector.x < 0 && vector.y == 0)
		return (WEST);
	else if (vector.x == 0 && vector.y > 0)
		return (SOUTH);
	else if (vector.x == 0 && vector.y < 0)
		return (NORTH);
	else if (vector.x != 0 && vector.y != 0)
	{
		if (vector.x > 0 && vector.y > 0)
			return (SOUTHEAST);
		if (vector.x > 0 && vector.y < 0)
			return (NORTHEAST);
		if (vector.x < 0 && vector.y > 0)
			return (SOUTHWEST);
		if (vector.x < 0 && vector.y < 0)
			return (NORTHWEST);
	}
	return (-1);
}

float	d_fisheye(t_pt pt1, t_pt pt2, float deg)
{
	float	x;
	float	y;
	float	p_fisheye;

	x = (pt1.x - pt2.x) * (pt1.x - pt2.x);
	y = (pt1.y - pt2.y) * (pt1.y - pt2.y);
	p_fisheye = sqrtf(x + y) * cos(deg / 180 * M_PI);
	return (p_fisheye);
}

float	d_betw(t_pt pt1, t_pt pt2)
{
	float	x;
	float	y;

	x = (pt1.x - pt2.x) * (pt1.x - pt2.x);
	y = (pt1.y - pt2.y) * (pt1.y - pt2.y);
	return (sqrtf(x + y));
}

float	mod_angle(float angle, float mod)
{
	while (angle < 0 || angle >= mod)
	{
		if (angle < 0)
			angle += mod;
		else if (angle >= mod)
			angle -= mod;
	}
	return (angle);
}
