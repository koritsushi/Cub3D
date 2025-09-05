/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:13:40 by booi              #+#    #+#             */
/*   Updated: 2025/09/04 13:13:42 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

// img pointer texture;
// texture = mlx_to_image();
// x = texture column;

// int	i;
// i = ceil_height + 1;

// y = start_y;
// while (i < tex_height)  
// {
// 	y = ceil_height + i;
// 	colour = get_colour(texture);
// 	data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = colour;
// 	i++;
// }


// int	get_colour(void* img, int x, int y)
// {
// 	img->addr[y * (img->size_line / 4) + x] = colour;
// 	int	src_height;
// 	int	dst_height;
// 	float	src_ratio;
// 	float	dst_ratio;

// 	src_height = img_height;
// 	dst_height = tex_height;
// 	return (0);
// }

// function ()
// {
//     int i;

//     i = 0;
//     while (i < dst_h)
//     {
//        target_y = round(i / dst_h * src_h);
//        const_x = get_x(pt, vector);
//        colour = addr[target_y * (size_line / 4) + const_x];

//        img.addr[(target_y + ceil_h) * (size_line / 4) + const_x] = colour;
//        i++;
//     }
// }

void* init_texture(t_cub* data, char *filepath, int i)
{
    void*   p;
    int     width;
    int     height;

    width = 64;
    height = 64;

    data->texture[i].img = mlx_xpm_file_to_image(data->vars.mlx, filepath, &width, &height);
    data->texture[i].addr = (int*)mlx_get_data_addr(data->texture[i].img, &data->texture[i].bpp, &data->texture[i].size_line, &data->texture[i].endian);
}