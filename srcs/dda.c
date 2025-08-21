/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:51:26 by booi              #+#    #+#             */
/*   Updated: 2025/08/20 13:51:28 by booi             ###   ########.fr       */
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

int	is_int(float n);
float	d_to_border(float pt, float dir);
int		pt_on_solid(t_cub* data, t_pt pt);
t_pt	next_checkpoint(t_cub* data);


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

int	is_wholenum(float n)
{
	if (fabsf(n - round(n)) < PRECISION)
		return (1);
	return (0);
}

int	pt_on_solid(t_cub* data, t_pt pt)
{
	printf("pt_on_solid: running\n");

	//else check for edge and diagonal cases
	if (is_wholenum(pt.x) && is_wholenum(pt.y))
	{
		printf("pt is on a diagonal\n");

	}
	if (is_wholenum(pt.x))
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
	
	//check if x or y is on border
	// check direction
	// if x and x.dir > 0, check right cell[floor(y)][round(x)]
	// if x and x.dir < 0, check left cell[floor(y)][round(x) - 1]
	// if y and y.dir > 0, check down cell[round(y)][floor(x)]
	// if y and y.dir < 0, check up cell[round(y) - 1][floor(x)]

	return (0);



}

t_pt	next_checkpoint(t_cub* data)
{
	float 	x; 
	float 	y;
	t_pt	p;

	x = d_to_border(data->p1.x, data->dir_pt.x);
	y = d_to_border(data->p1.y, data->dir_pt.y);
	p.x = 0;
	p.y = 0;

	// while (!pt_on_solid)
	// {
	
	// }

	// if (x < y)
	// {
	// 	p.x = data->p1.x + (x * data->dir_pt.x) ;
	// 	p.y = data->p1.y + (x * data->dir_pt.y) ;
	// }
	// else
	// {
	// 	p.x = data->p1.x + (y * data->dir_pt.x) ;
	// 	p.y = data->p1.y + (y * data->dir_pt.y) ;
	// }
	// printf("p (%f, %f)\n", 1.0, 1.0); 
	// printf("p\n");
	return (p);
}