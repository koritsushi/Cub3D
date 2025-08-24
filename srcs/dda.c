/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:51:26 by booi              #+#    #+#             */
/*   Updated: 2025/08/21 22:00:05 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

//p1, direction
// find next checkpoint pt
// determine which cell to check
// if cell is solid, return pt
// else, loop

float	d_to_border(float pt, float dir);
int	orthogonal_solid(t_cub* data, t_pt pt);
int	diagonal_solid(t_cub* data, t_pt pt);
int	pt_on_solid(t_cub* data, t_pt pt);
float	next_xy(float p, float vector);
t_pt	next_checkpoint(t_pt src, t_pt vector);
t_pt	end_point(t_cub* data);


float	d_to_border(float pt, float dir)
{
	float	final;

	final = 0;	

	if (dir > 0)
		final = ceil(pt);
	else
		final = floor(pt);
	return ((final - pt) / dir); 
}

int	orthogonal_solid(t_cub* data, t_pt pt)
{
	if (data->dir_pt.x > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.x < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
	}
	else if (data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	return (0);
}

int	diagonal_solid(t_cub* data, t_pt pt)
{
	//if diagonal is solid || two sides are solid, return 1
	// else return 0
	if (data->dir_pt.x > 0 && data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	else if (data->dir_pt.x > 0 && data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
	}
	else if (data->dir_pt.x < 0 && data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.x < 0 && data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	return (0);
}

int	pt_on_solid(t_cub* data, t_pt pt)
{
	printf("pt_on_solid: running\n");

	if (!is_wholenum(pt.x) && !is_wholenum(pt.y))
	{
		printf("keep running, no need to check cell yet\n");
		return (0);
	}
	//else check for edge and diagonal cases
	else if (is_wholenum(pt.x) && is_wholenum(pt.y))
	{
		printf("pt is on a diagonal\n");
		if (fabsf(data->dir_pt.x) > PRECISION && fabsf(data->dir_pt.y) > PRECISION)
		{
			diagonal_solid(data, pt);
			printf("pt will move diagonally\n");
		}
		else if (fabsf(data->dir_pt.x) > PRECISION || fabsf(data->dir_pt.y) > PRECISION)
		{
			orthogonal_solid(data, pt);
			printf("pt will move orthogonally\n");
		}
		// both x and y == 0 is not possible, since struct initialises with a direction
	}
	else if (is_wholenum(pt.x))
	{
		if (data->dir_pt.x > 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x));
		if (data->dir_pt.x < 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x) - 1);
	}
	else if (is_wholenum(pt.y))
	{
		if (data->dir_pt.y > 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)floor(pt.x));
		if (data->dir_pt.y < 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y) - 1, (int)floor(pt.x));
	}
	else
		printf("keep running, no need to check cell yet\n");
	
	//check if x or y is on border
	// check direction
	// if x and x.dir > 0, check right cell[floor(y)][round(x)]
	// if x and x.dir < 0, check left cell[floor(y)][round(x) - 1]
	// if y and y.dir > 0, check down cell[round(y)][floor(x)]
	// if y and y.dir < 0, check up cell[round(y) - 1][floor(x)]

	return (0);
}

float	next_xy(float p, float vector)
{
	if (!is_zero(vector))
	{
		if  (vector > 0)
			return (floor(p) + 1); 
		else if (vector < 0 && is_wholenum(p))
			return (floor(p) - 1); 
		else if (vector < 0)
			return (floor(p)); 
	}
	return (-1);
}

t_pt	next_checkpoint(t_pt src, t_pt vector)
{
	int	next_x;
	int	next_y;
	float	factor;
	t_pt	p;
	t_pt	temp;

	p.x = -1;
	p.y = -1;
	temp = snap_xy(src);
	next_x = next_xy(temp.x, vector.x);
	next_y = next_xy(temp.y, vector.y);

	if (next_x == -1 && next_y == -1)
		return (p);
	else if (next_x == -1)
		factor = (next_y - src.y) / vector.y;
	else if (next_y == -1)
		factor = (next_x - src.x) / vector.x;
	else
		factor = fmin((next_x - src.x) / vector.x, (next_y - src.y) / vector.y);

	p.x = src.x + (vector.x * factor);
	p.y = src.y + (vector.y * factor);

	return (p);
}

t_pt	end_point(t_cub* data)
{
	t_pt	src;

	src = data->p1;
	// if p1 is on cell border and facing the wall, terminate.
	// while (!is_solid(data, src))
	// {
	// 	src = next_checkpoint(src, data->dir_pt);
	// }
	return (src);
}