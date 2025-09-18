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

t_pt    vector_of(float angle);
int	    is_wholenum(float n);
int     is_zero(float n);
int		is_solid(char cell);
int     is_bordering(t_pt pt);
int     direction_of(t_pt vector);
t_pt    snap_xy(t_pt pt);
float   d_fisheye(t_pt pt1, t_pt pt2, float angle);
float   d_betw(t_pt pt1, t_pt pt2);
float   mod_angle(float angle, float mod);

t_pt    vector_of(float angle)
{
    t_pt    p;

	p.x = cos(angle / 180 * M_PI) * MOVE_SPEED;
	p.y = sin(angle / 180 * M_PI) * MOVE_SPEED * (-1);
    // if (angle == 0)
    //     p.y = 0;
    return (p);
}

int	is_wholenum(float n)
{
	// if (fabs(n - round(n)) < PRECISION)
	if (n == round(n))
		return (1);
	return (0);
}

// int     is_zero(float n)
// {
//     if(fabs(n) < PRECISION)
//         return (1);
//     return (0);
// }

int		is_solid(char cell)
{
	if (cell == '1')
		return (1);
	return (0);
}

int     is_bordering(t_pt pt)
{
	int	loc;

	loc = 0;
	if (is_wholenum(pt.x))
		loc++;
	if (is_wholenum(pt.y))
		loc += 2;

    return (loc);
    // 0 is within cell, 1 is on vside, 2 is on hside, 3 is on corner.
}

int     direction_of(t_pt vector)
{
	if (vector.x == 0 && vector.y == 0)
    // if (is_zero(vector.x) && is_zero(vector.y))
        return (HERE);
	else if (vector.x > 0 && vector.y == 0)
	// else if (!is_zero(vector.x) && is_zero(vector.y) && vector.x > 0)
        return (EAST);
	else if (vector.x < 0 && vector.y == 0)
	// else if (!is_zero(vector.x) && is_zero(vector.y) && vector.x < 0)
        return (WEST);
	else if (vector.x == 0 && vector.y > 0)
	// else if (is_zero(vector.x) && !is_zero(vector.y) && vector.y > 0)
        return (SOUTH);
	else if (vector.x == 0 && vector.y < 0)
	// else if (is_zero(vector.x) && !is_zero(vector.y) && vector.y < 0)
        return (NORTH);
	else if (vector.x != 0 && vector.y != 0)
	// else if (!is_zero(vector.x) && !is_zero(vector.y))
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

// t_pt    snap_xy(t_pt pt)
// {
//     // printf("before snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
//     if (is_wholenum(pt.x))
//         pt.x = roundf(pt.x);
//     if (is_wholenum(pt.y))
//         pt.y = roundf(pt.y);
//     // printf("after snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
//     return (pt);
// }

float   d_fisheye(t_pt pt1, t_pt pt2, float angle)
{
    float x;
    float y;
    float p_fisheye;

    x = (pt1.x - pt2.x) * (pt1.x - pt2.x);
    y = (pt1.y - pt2.y) * (pt1.y - pt2.y);
    p_fisheye = sqrtf(x + y) * cos(angle / 180 * M_PI);

    return (p_fisheye);
}

float   d_betw(t_pt pt1, t_pt pt2)
{
    float x;
    float y;

    x = (pt1.x - pt2.x) * (pt1.x - pt2.x);
    y = (pt1.y - pt2.y) * (pt1.y - pt2.y);

    return (sqrtf(x + y));
}

float   mod_angle(float angle, float mod)
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

float angle_diff(float angle1, float angle2)
{
    float   p;

    p = fabs(angle1 - angle2);
    if (p > 180)
        return (360 - p);
    return (p);
}

int nb_units(int x)
{
    int   p;
    int   i;

    int mid = S_WIDTH / 2;
    p = mid;
    i = -1;

    if (x < mid)
    {
        while (++i < x)
            p += (mid - i - 1);
    }
    else
    {
        i = mid - 1;
        p = mid * (mid + 1) / 2;
        while (++i < x)
            p += (i - mid);
    }

    return (p);
}

int is_inwall(t_cub* data, t_pt pt)
{
    int x;
    int y;

    x = floor(pt.x);
    y = floor(pt.y);
    if (!is_bordering(pt))
        return (is_solid(data->map[y][x]));
    else if (is_bordering(pt) == 1)
        return (is_solid(data->map[y][x]) || is_solid(data->map[y][x - 1]));
    else if (is_bordering(pt) == 2)
        return (is_solid(data->map[y][x]) || is_solid(data->map[y - 1][x]));
    else if (is_bordering(pt) == 3)
        return (is_solid(data->map[y][x]) || is_solid(data->map[y][x - 1]) || is_solid(data->map[y - 1][x]) || is_solid(data->map[y - 1][x - 1]));
    else
        return (-1);
}

double   ft_power(double i, int n)
{
    double  p;

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