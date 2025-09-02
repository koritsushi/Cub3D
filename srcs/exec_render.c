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

void colour_col(t_cub* data, int col)
{
    int i;
    float   ratio;
    int cf_height;
    int txt_height;

    ratio = 0.2;
    cf_height = ratio * S_HEIGHT;
    txt_height = (1 - (2 * ratio)) * S_HEIGHT;
    // printf("cf %d, txt %d\n", cf_height, txt_height);
    int color1 = create_colourcode(0, 255, 0, 0);
    int color2 = create_colourcode(0, 0, 255, 0);
    int color3 = create_colourcode(0, 0, 0, 255);

    i = -1;
    while (++i < cf_height)
        data->snapshot.addr[i * (data->snapshot.size_line / 4) + col] = color1;
    i --;
    while (++i < cf_height + txt_height)
        data->snapshot.addr[i * (data->snapshot.size_line / 4) + col] = color2;
    i --;
    while (++i < S_HEIGHT)
        data->snapshot.addr[i * (data->snapshot.size_line / 4) + col] = color3;
}

void render_snapshot(t_cub* data)
{
    int i;

	data->snapshot.img = mlx_new_image(data->vars.mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);

    i = -1;
    while (++i < S_WIDTH) // why need 4 here?
        colour_col(data, i);
	mlx_put_image_to_window(data->vars.mlx, data->vars.win, data->snapshot.img, 0, 0);
    mlx_destroy_image(data->vars.mlx, data->snapshot.img);
}