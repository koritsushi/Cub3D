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
double	get_step(t_cub *data)
{
	double	p;
	double	max;

	max = tan(FOV / 2.0 / 180 * M_PI) * 2;
	p = max / (S_WIDTH);
	printf("get_step: is %f, %f\n", p, tan(60 / 180.0 * M_PI));
	return (p);
}

void	update_cameraplane(t_cub *data)
{
	double	factor;

	data->camera_plane = ft_rotate(data->dir_pt, -90);
	factor = tan(FOV / 2.0 / 180 * M_PI);
	data->camera_plane.x *= factor;
	data->camera_plane.y *= factor;
}
