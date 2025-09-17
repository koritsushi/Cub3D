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

float srcx_of(t_pt pt, t_pt vector)
{
    if (texture_of(pt, vector) == NORTH)
        return (ceil(vector.x) - vector.x);
    else if (texture_of(pt, vector) == EAST)
        return (ceil(vector.y) - vector.y);
    else if (texture_of(pt, vector) == SOUTH)
        return (vector.x - floor(vector.x));
    else if (texture_of(pt, vector) == WEST)
        return (vector.y - floor(vector.y));
    return (-1);
}

void fill_texture(t_cub* data, int y)
{
    int src_h;
    int dst_h;
    int colour;
    int txt;

    src_h = data->srcy1 - data->srcy0 + 1;
    dst_h = data->dsty1 - data->dsty0 + 1;
    txt = texture_of(data->endpt, data->ray_vector) - 1;
    
    colour = data->texture[txt].addr[y * (data->snapshot.size_line / 4) + data->dstx];
    data->snapshot.addr[y * (data->snapshot.size_line / 4) + data->dstx] = colour;
}

void init_texture(t_cub* data, char *filepath, int i)
{
    void*   p;
    int     width;
    int     height;

    width = 1024;
    height = 1024;

    data->texture[i].img = mlx_xpm_file_to_image(data->mlx, filepath, &width, &height);
    data->texture[i].addr = (int*)mlx_get_data_addr(data->texture[i].img, &data->texture[i].bpp, &data->texture[i].size_line, &data->texture[i].endian);
}

int texture_of(t_pt pt, t_pt vector)
{
    if (is_bordering(pt) == 1 && vector.x > 0)
        return (WEST);
    else if (is_bordering(pt) == 1 && vector.x < 0)
        return (EAST);
    else if (is_bordering(pt) == 1 && vector.y > 0)
        return (NORTH);
    else if (is_bordering(pt) == 1 && vector.y < 0)
        return (SOUTH);
    else if (is_bordering(pt) == 3)
    {
        if (direction_of(vector) == NORTH || direction_of(vector) == NORTHEAST)
            return (SOUTH);
        else if (direction_of(vector) == EAST || direction_of(vector) == SOUTHEAST)
            return (WEST);
        else if (direction_of(vector) == SOUTH || direction_of(vector) == SOUTHWEST)
            return (NORTH);
        else if (direction_of(vector) == WEST || direction_of(vector) == NORTHWEST)
            return (EAST);
    }
    return (0);
}