/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:13:23 by booi              #+#    #+#             */
/*   Updated: 2025/09/17 11:13:24 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

// returns the atan step for each col on the camera plane.
double	get_step(t_cub* data)
{
	double	p;
	double	max;
	int		cols;

	max = tan(FOV / 2.0 / 180 * M_PI) * 2;
	// cols = S_WIDTH / 2;
	p = max / (S_WIDTH);
	// p = atan(p * 320) / M_PI * 180;

	printf("get_step: is %f, %f\n", p, tan(60 / 180.0 * M_PI));
	return (p);
}

int	dist(t_cub* data)
{
	int	i;
	double	angle;
	double	step;

	i = 0;
	step = get_step(data);
	while (i <= S_WIDTH)
	{
		angle = atan((S_WIDTH / 2 - i) * step) / M_PI * 180;
		angle = mod_angle(data->dir_angle + angle, 360);
		// printf("angle is %f\n", angle);
		i++;
	}
	return (0);
}

//find camera start point
// if d_camerapoint > d_endpoint, LOS is blocked - render all wall
// else count camerapoint, dir_pt vector to endpoint to get distance (no need fisheye) -> this gives distance
// use distance to count ratio
// increment by step to render next column