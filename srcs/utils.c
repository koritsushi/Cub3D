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
int     is_zero(float n);
int		is_solid(char cell);
int     direction_of(t_pt vector);

t_pt    vector_of(float angle)
{
    t_pt    p;

	p.x = cos(angle / 180 * M_PI) * MOVE_SPEED;
	p.y = sin(angle / 180 * M_PI) * MOVE_SPEED * (-1);
    return (p);
}

int     is_zero(float n)
{
    if(fabsf(n) < PRECISION)
        return (1);
    return (0);
}

int		is_solid(char cell)
{
	if (cell == '1')
		return (1);
	return (0);
}

int     direction_of(t_pt vector)
{
	if (is_zero(vector.x) && is_zero(vector.y))
        return (HERE);
	else if (!is_zero(vector.x) && is_zero(vector.y) && vector.x > 0)
        return (EAST);
	else if (!is_zero(vector.x) && is_zero(vector.y) && vector.x < 0)
        return (WEST);
	else if (is_zero(vector.x) && !is_zero(vector.y) && vector.y > 0)
        return (SOUTH);
	else if (is_zero(vector.x) && !is_zero(vector.y) && vector.y < 0)
        return (NORTH);
	else if (!is_zero(vector.x) && !is_zero(vector.y))
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
}