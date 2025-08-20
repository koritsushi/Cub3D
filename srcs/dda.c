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

float	d_to_border(float pt, float dir);
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


t_pt	next_checkpoint(t_cub* data)
{
	float 	x; 
	float 	y;
	t_pt	p;
	
	x = d_to_border(data->p1.x, data->dir_pt.x);
	y = d_to_border(data->p1.y, data->dir_pt.y);
	p.x = 0;
	p.y = 0;

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