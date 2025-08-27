/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:51:26 by booi              #+#    #+#             */
/*   Updated: 2025/08/27 13:37:25 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

float	next_xy(float p, float vector);
t_pt	next_checkpoint(t_pt src, t_pt vector);

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

	printf("next: x %d, y %d\n", next_x, next_y);
	if (next_x == -1 && next_y == -1)
		return (p);
	else if (next_x == -1)
		factor = (next_y - src.y) / vector.y;
	else if (next_y == -1)
		factor = (next_x - src.x) / vector.x;
	else
		factor = fmin((next_x - src.x) / vector.x, (next_y - src.y) / vector.y);
	// printf("next: factor %f\n", factor);
	// printf("next: src (%f,%f)\n", src.x, src.y);

	p.x = src.x + (vector.x * factor);
	p.y = src.y + (vector.y * factor);

	return (p);
}
