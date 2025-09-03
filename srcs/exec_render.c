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

int	render_col(t_cub* data)
{
	data->snapshot.img = mlx_new_image(data->vars.mlx, 1, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);
	//fill in 3 column parts
    mlx_destroy_image(data->vars.mlx, data->snapshot.img);
    return (0);

}

int render_screen(t_cub* data)
{
    int i;

    i = 0;
    while (i < S_WIDTH)
    {
        render_col(data);
        i++;
    }
    return (0);
}

int create_colourcode(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

float set_ratio(t_cub* data, int x)
{
    float   angle_inc;
    float   angle;
    t_pt    endpt;
    float   dist;

    angle_inc = (float)FOV / (float)S_WIDTH;
    angle = mod_angle(data->dir_angle + (FOV / 2) - (x * angle_inc), 360);
    // endpt = end_point(data, vector_of(angle));
    dist = d_fisheye(data->p1, endpt, FOV / 2 - (x * angle_inc));
    dist = d_betw(data->p1, endpt);
    // printf("dist %f\n", dist);
    if (dist <= CLOSEUP)
    {
        // dist = d_betw(data->p1, endpt);
        // return ((float)(dist - CLOSEUP) / (float)(HORIZON - CLOSEUP) * 0.5);
        return (0);
    }
    if (dist < HORIZON)
        return ((float)(dist - CLOSEUP) / (float)(HORIZON - CLOSEUP) * 0.5);
    else
        return (0.5);
}

void colour_col(t_cub* data, int x)
{
    int y;
    float   ratio;
    int cf_height;
    int txt_height;

    // ratio = 0.2;
    ratio = set_ratio(data, x);
    // printf("colour_col: ratio %f\n", ratio);
    cf_height = ratio * S_HEIGHT;
    txt_height = (1 - (2 * ratio)) * S_HEIGHT;
    // printf("cf %d, txt %d\n", cf_height, txt_height);
    int color1 = create_colourcode(0, 255, 0, 0);
    int color2 = create_colourcode(0, 0, 255, 0);
    int color3 = create_colourcode(0, 0, 0, 255);

    y = -1;
    while (++y < cf_height)
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color1;
    y --;
    while (++y < cf_height + txt_height)
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color2;
    y --;
    while (++y < S_HEIGHT)
        data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = color3;
}

void render_snapshot(t_cub* data)
{
    int i;

	data->snapshot.img = mlx_new_image(data->vars.mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);

    i = -1;
    while (++i < S_WIDTH)
        colour_col(data, i);
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->snapshot.img, 0, 0);
    mlx_destroy_image(data->vars.mlx, data->snapshot.img);
}