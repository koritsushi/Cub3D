/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
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

int		is_wholenum(float n);
int		is_solid(char cell);
int		is_bordering(t_pt pt);
int		is_inwall(t_cub *data, t_pt pt);

int	is_wholenum(float n)
{
	if (n == round(n))
		return (1);
	return (0);
}

int	is_solid(char cell)
{
	if (cell == '1')
		return (1);
	return (0);
}

// 0 is within cell, 1 is on vside, 2 is on hside, 3 is on corner.
int	is_bordering(t_pt pt)
{
	int	loc;

	loc = 0;
	if (is_wholenum(pt.x))
		loc++;
	if (is_wholenum(pt.y))
		loc += 2;
	return (loc);
}

int	is_inwall(t_cub *data, t_pt pt)
{
	int	x;
	int	y;

	x = floor(pt.x);
	y = floor(pt.y);
	if (!is_bordering(pt))
		return (is_solid(data->map[y][x]));
	else if (is_bordering(pt) == 1)
		return (is_solid(data->map[y][x]) || is_solid(data->map[y][x - 1]));
	else if (is_bordering(pt) == 2)
		return (is_solid(data->map[y][x]) || is_solid(data->map[y - 1][x]));
	else if (is_bordering(pt) == 3)
		return (is_solid(data->map[y][x])
			|| is_solid(data->map[y][x - 1])
			|| is_solid(data->map[y - 1][x])
			|| is_solid(data->map[y - 1][x - 1]));
	else
		return (-1);
}
