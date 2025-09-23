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

	max = tan(FOV / 2.0 / 180 * M_PI) * 2;
	p = max / (S_WIDTH);

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


void	update_rayinfo(t_cub* data)
{
	// float	ray_angle;
	// t_pt	endpt;
	// t_pt	ray_vector;
    // int     ray_texture;
	// t_pt	ray_start;
	data->step = get_step(data);


}

void	update_cameraplane(t_cub* data)
{
	double	factor;

	data->camera_plane = ft_rotate(data->dir_pt, -90);
	factor = tan(FOV / 2.0 / 180 * M_PI);
	// printf("update_cameraplan: (%f, %f), factor %f\n", data->camera_plane.x, data->camera_plane.y, factor);
	data->camera_plane.x *= factor;
	data->camera_plane.y *= factor;
	// printf("update_cameraplan: factor %f (%f, %f)", factor, data->camera_plane.x, data->camera_plane.y);
}

double	get_ratio(t_cub* data, int i)
{
	double	angle;
	double	dist;
	double	factor;
	double	d_cam;
	double	d_wall;

	angle = atan((S_WIDTH / 2 - i) * data->step);
	d_cam = fabs(D_CAMERA / cos(angle));
	d_wall = d_betw(data->p1, end_point(data, data->p1, data->ray_vector));
	if (d_cam >= d_wall)
		return (-d_wall / d_cam);		
	else
	{
		factor = d_cam / sqrt(ft_power(data->ray_vector.x, 2) + ft_power(data->ray_vector.y, 2));
		data->ray_start.x = data->p1.x + factor * data->ray_vector.x;
		data->ray_start.y = data->p1.y + factor * data->ray_vector.y;
		dist = d_betw(data->ray_start, end_point(data, data->ray_start, data->dir_pt));
		dist = data->d_ray;
		// dist = d_fisheye(ray_start, end_point(data, ray_start, data->dir_pt), fabs(angle));
		if (dist >= HORIZON)
			return (0.5);
		else
			return (dist / HORIZON * 0.5);
	}
}

//find camera start point
// if d_camerapoint > d_endpoint, LOS is blocked - render all wall
// else count camerapoint, dir_pt vector to endpoint to get distance (no need fisheye) -> this gives distance
// use distance to count ratio
// increment by step to render next column