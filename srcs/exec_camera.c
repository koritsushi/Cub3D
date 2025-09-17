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

	max = tan(FOV / 2.0 / 180 * M_PI);
	cols = S_WIDTH / 2;
	p = max / cols;
	// p = atan(p * 320) / M_PI * 180;

	printf("get_step: is %f, %f\n", p, tan(60 / 180.0 * M_PI));
	return (p);
}



//find camera start point
// if d_camerapoint > d_endpoint, LOS is blocked - render all wall
// else count camerapoint, dir_pt vector to endpoint to get distance (no need fisheye) -> this gives distance
// use distance to count ratio
// increment by step to render next column