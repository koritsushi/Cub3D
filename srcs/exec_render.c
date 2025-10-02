/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:58:47 by booi              #+#    #+#             */
/*   Updated: 2025/08/29 16:58:48 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

void	setup_srcdst(t_cub *data)
{
	int	txt_height;
	int	cf_height;

	txt_height = (int)(S_HEIGHT / data->d_ray);
	if (txt_height > S_HEIGHT)
	{
		data->srcy0 = (int)((1.0 - data->d_ray)
				/ 2 * data->ray_texture->height);
		data->srcy1 = data->ray_texture->height - data->srcy0;
		txt_height = S_HEIGHT;
	}
	else
	{
		data->srcy0 = 0;
		data->srcy1 = data->ray_texture->height - 1;
	}
	cf_height = (S_HEIGHT - txt_height) / 2;
	if (cf_height < 0)
		cf_height = 0;
	data->dsty0 = cf_height;
	data->dsty1 = S_HEIGHT - 1 - cf_height;
}

void	colour_col(t_cub *data, int x)
{
	int	y;

	y = -1;
	while (++y < data->dsty0)
		data->snapshot.addr[y * (data->snapshot.size_line / 4) + x]
			= data->c_col;
	y --;
	while (++y < data->dsty1)
		fill_texture(data, y);
	y --;
	while (++y < S_HEIGHT)
		data->snapshot.addr[y * (data->snapshot.size_line / 4) + x]
			= data->f_col;
}

void	render_snapshot(t_cub *data)
{
	int	i;

	data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	data->snapshot.addr = (int *)(mlx_get_data_addr(data->snapshot.img,
		&data->snapshot.bpp,
		&data->snapshot.size_line,
		&data->snapshot.endian));
	i = -1;
	while (++i < S_WIDTH)
	{
		update_render_info(data, i);
		colour_col(data, i);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->snapshot.img, 0, 0);
	mlx_destroy_image(data->mlx, data->snapshot.img);
}

void	update_srcx(t_cub *data)
{
	int	width;

	width = data->ray_texture->width;
	if (texture_of(data->ray_endpt, data->ray_vector) == NORTH)
		data->srcx = (int)((ceil(data->ray_endpt.x) - data->ray_endpt.x)
				* width);
	else if (texture_of(data->ray_endpt, data->ray_vector) == EAST)
		data->srcx = (int)((ceil(data->ray_endpt.y) - data->ray_endpt.y)
				* width);
	else if (texture_of(data->ray_endpt, data->ray_vector) == SOUTH)
		data->srcx = (int)((data->ray_endpt.x - floor(data->ray_endpt.x))
				* width);
	else if (texture_of(data->ray_endpt, data->ray_vector) == WEST)
		data->srcx = (int)((data->ray_endpt.y - floor(data->ray_endpt.y))
				* width);
}

void	update_render_info(t_cub *data, int i)
{
	double	angle;
	double	step;

	step = 2.0 * i / S_WIDTH - 1;
	data->ray_vector.x = data->dir_pt.x + step * data->camera_plane.x;
	data->ray_vector.y = data->dir_pt.y + step * data->camera_plane.y;
	data->ray_angle = acos(1
			/ ft_hypot(data->ray_vector.x, data->ray_vector.y)) / M_PI * 180;
	if (isnan(data->ray_angle))
		data->ray_angle = 0;
	data->ray_endpt = end_point(data, data->p1, data->ray_vector);
	data->d_ray = d_fisheye(data->p1, data->ray_endpt, data->ray_angle);
	data->txt_n = texture_of(data->ray_endpt, data->ray_vector);
	if (texture_of(data->ray_endpt, data->ray_vector) != -1)
		data->ray_texture = &data->texture[data->txt_n - 1];
	update_srcx(data);
	data->dstx = i;
	setup_srcdst(data);
}
