/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_endpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:26:42 by booi              #+#    #+#             */
/*   Updated: 2025/08/27 13:26:43 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

int	check_spt(char** map, t_pt pt, t_pt vector, int side);
int	check_ocpt(char** map, int x, int y, t_pt vector);
int	check_dcpt(char** map, int x, int y, t_pt vector);
int	is_stop(char** map, t_pt pt, t_pt vector);
t_pt	end_point(t_cub* data, t_pt vector);

int	check_spt(char** map, t_pt pt, t_pt vector, int side)
{
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (side == 1)
	{
		if (vector.x > 0)
			return (is_solid(map[y][x]));
		else if (vector.x < 0)
			return (is_solid(map[y][x - 1]));
		else
			return (0);
	}
	else if (side == 2)
	{
		if (vector.y > 0)
			return (is_solid(map[y][x]));
		else if (vector.y < 0)
			return (is_solid(map[y - 1][x]));
		else
			return (0);
	}
	else
		return (-1);
}

int	check_ocpt(char** map, int x, int y, t_pt vector)
{
	if (direction_of(vector) == NORTH)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x])));
	else if (direction_of(vector) == EAST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])));
	else if (direction_of(vector) == SOUTH)
		return ((is_solid(map[y][x]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y][x])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y - 1][x])));
	else if (direction_of(vector) == WEST)
		return ((is_solid(map[y][x - 1]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x])));
}

int	check_dcpt(char** map, int x, int y, t_pt vector)
{
	if (direction_of(vector) == NORTHWEST)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				is_solid(map[y - 1][x - 1]));
	else if (direction_of(vector) == NORTHEAST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				is_solid(map[y - 1][x]));
	else if (direction_of(vector) == SOUTHEAST)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				is_solid(map[y][x]));
	else if (direction_of(vector) == SOUTHWEST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				is_solid(map[y][x - 1]));
}

// pt should be on border
int	is_stop(char** map, t_pt pt, t_pt vector)
{
	int		x;
	int		y;
	t_pt	temp;

	temp = snap_xy(pt);
	x = floorf(temp.x);
	y = floorf(temp.y);
	temp.x = x;
	temp.y = y;
	if (is_bordering(pt) == 1 || is_bordering(pt) == 2)
		return (check_spt(map, temp, vector, is_bordering(pt)));
	else if (is_bordering(pt) == 3)
	{
		if (direction_of(vector) <= 4)
			return(check_ocpt(map, x, y, vector));
		else if (direction_of(vector) <= 8)
			return(check_dcpt(map, x, y, vector));
	}
	else
		return (-1);
}

t_pt	end_point(t_cub* data, t_pt vector)
{
	t_pt	pt;

	pt = data->p1;
	if (is_bordering(pt) && is_stop(data->map, pt, vector))
		return (pt);
	else
		pt = next_checkpoint(pt, vector);

	while (!is_stop(data->map, pt, vector))
	{
		pt = next_checkpoint(pt, vector);
		printf("end_point: pt(%f,%f)\n", pt.x, pt.y);
	}
	return (pt);
}
