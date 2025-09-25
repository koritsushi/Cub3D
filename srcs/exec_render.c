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

int create_colourcode(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

float adj_dist(t_cub* data, int x)
{
    float   angle_inc;
    float   angle;
    t_pt    endpt;
    float   dist;

    angle_inc = (float)FOV / (float)S_WIDTH;
    angle = mod_angle(data->dir_angle + (FOV / 2) - (x * angle_inc), 360);
    // angle_inc = 1.00000 / (S_WIDTH / 2) / (S_WIDTH / 2) * FOV;
    // angle = mod_angle(data->dir_angle + (FOV / 2) - (float)(nb_units(x) * angle_inc), 360);
    endpt = end_point(data, data->p1, vector_of(angle));
    return d_fisheye(data->p1, endpt, angle_diff(angle, data->dir_angle));
}

void colour_col(t_cub* data, int x)
{
	// data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
    // data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);
    int y;
    // float   ratio;
    int cf_height;
    int txt_height;
    int ratio;

    // ratio = set_ratio(data, x);
    // if (ratio < 0)
    //     ratio = 0;
    // printf("colour_col: ratio %f\n", ratio);
    txt_height = (int)(S_HEIGHT / data->d_ray);
    if (txt_height > S_HEIGHT)
        txt_height = S_HEIGHT;
    cf_height = (S_HEIGHT - txt_height) / 2;
    if (cf_height < 0)
        cf_height = 0;

    data->srcy0 = 0;
    data->srcy1 = data->ray_texture->height - 1;
    data->dstx = x;
    data->dsty0 = cf_height;
    data->dsty1 = S_HEIGHT - 1 - cf_height;
    // printf("cf %d, txt %d\n", cf_height, txt_height);
    int color1 = create_colourcode(0, 100, 0, 0);
    int color2 = create_colourcode(0, 0, 100, 0);
    int color3 = create_colourcode(0, 0, 0, 200);

    // if (x == S_WIDTH / 2)
    // {
    //     printf("colour col: x %d txt %d, cf %d, d_ray %f ", x, txt_height, cf_height, data->d_ray);
    //     printf("colour col: rayangle %f, hypot %f\n", data->ray_angle, ft_hypot(data->ray_vector.x, data->ray_vector.y));
    //     // return;
    // }

    y = -1;
    while (++y < cf_height)
    {
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color1;
    }
    y --;
    while (++y < cf_height + txt_height)
    {
        // fill_texture(data, y); // need to address this fill_texture function 
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color2;
    }
    y --;
    while (++y < S_HEIGHT)
    {
// printf("debug %d\n", data->snapshot.addr[y * (data->snapshot.size_line / 4) + x]);
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color3;
// printf("debug %d\n", data->snapshot.addr[y * (data->snapshot.size_line / 4) + x]);
    }
}

void render_snapshot(t_cub* data)
{
    int i;

	data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);

    i = -1;
    while (++i < S_WIDTH)
    {
        update_render_info(data, i);
        colour_col(data, i); 
    }
	mlx_put_image_to_window(data->mlx, data->win, data->snapshot.img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->win, data->texture[3].img, 0, 0);
    mlx_destroy_image(data->mlx, data->snapshot.img);
}

void    update_render_info(t_cub* data, int i)
{
    double  angle;
    double  step;

    // if (i > 0)
    // {
    //     step = 2.0 * (i - 1) / S_WIDTH - 1;
    //     data->ray_vector.x = data->dir_pt.x + step * data->camera_plane.x; 
    //     data->ray_vector.y = data->dir_pt.y + step * data->camera_plane.y; 
    //     angle = acos(1 / ft_hypot(data->ray_vector.x, data->ray_vector.y)) / M_PI * 180;
    // }
    step = 2.0 * i / S_WIDTH - 1;
    data->ray_vector.x = data->dir_pt.x + step * data->camera_plane.x; 
    data->ray_vector.y = data->dir_pt.y + step * data->camera_plane.y; 
    data->ray_angle = acos(1 / ft_hypot(data->ray_vector.x, data->ray_vector.y)) / M_PI * 180;
    if (isnan(data->ray_angle))
        data->ray_angle = 0;
    data->ray_endpt = end_point(data, data->p1, data->ray_vector);
    // data->d_ray = d_betw(data->p1, data->ray_endpt);
    data->d_ray = d_fisheye(data->p1, data->ray_endpt, data->ray_angle); 
    data->ray_texture = &data->texture[texture_of(data->ray_endpt, data->ray_vector) - 1];

    if (texture_of(data->ray_endpt, data->ray_vector) == NORTH)
        data->srcx = (int)((ceil(data->ray_endpt.x) - data->ray_endpt.x) * data->ray_texture->width);
    else if (texture_of(data->ray_endpt, data->ray_vector) == EAST)
        data->srcx = (int)((ceil(data->ray_endpt.y) - data->ray_endpt.y) * data->ray_texture->width);
    else if (texture_of(data->ray_endpt, data->ray_vector) == SOUTH)
        data->srcx = (int)((data->ray_endpt.x - floor(data->ray_endpt.x)) * data->ray_texture->width);
    else if (texture_of(data->ray_endpt, data->ray_vector) == WEST)
        data->srcx = (int)((data->ray_endpt.y - floor(data->ray_endpt.y)) * data->ray_texture->width);
    // printf("i %d, srcx %d\n", i, data->srcx);
    // data->srcx = 100; // needs a function
    // printf("update render info: %d %p %p %d\n", i, data->ray_texture, &data->texture[1], data->srcx);
    //data->texture[ray_texture] is the wall to use.
    // int y;
    // int x;
    // int color1 = create_colourcode(0, 255, 255, 255);
    // y = data->ray_endpt.y * 100;
    // x = data->ray_endpt.x * 100;
    // data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color1;
    // printf("update render info: x %f %d\n", data->ray_endpt.x, (int)data->ray_endpt.x);
    // printf("update render info: \n");
    // printf("update render info: i %d step %f %f %f d_ray %f\n", i, step, data->ray_vector.x, data->ray_vector.y, data->d_ray);
    // printf("update render info: x %d acos %f diff %f, (%d %d)\n", i, data->ray_angle, data->ray_angle - angle, x, y);
    // angle = (float)FOV / (float)S_WIDTH;
    // angle = 1.00000 / (S_WIDTH / 2) / (S_WIDTH / 2) * FOV;
	// angle = atan((S_WIDTH / 2 - i) * data->step) / M_PI * 180;
    // data->ray_angle = mod_angle(data->dir_angle + (FOV / 2) - (x * angle_inc), 360);
    // data->ray_angle = mod_angle(data->dir_angle + (FOV / 2) - (float)(nb_units(i) * angle_inc), 360);
	// data->ray_angle = mod_angle(data->dir_angle + angle, 360);
    // data->ray_vector = vector_of(data->ray_angle);
    // data->d_ray = d_fisheye(data->p1, data->ray_endpt, atan(ft_hypot(data->camera_plane.x, data->camera_plane.y)) / M_PI * 180);
    // data->dist = d_fisheye(data->p1, data->endpt, angle_diff(data->ray_angle, data->dir_angle));
    // printf("DEBUG!! endpt (%f, %f) vector (%f, %f)\n", data->endpt.x, data->endpt.y, data->ray_vector.x, data->ray_vector.y);
}