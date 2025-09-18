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
    
    // colour = create_colourcode(0, 100, 100, 100);
    colour = data->texture[txt].addr[y * (data->snapshot.size_line / 4) + data->dstx];
    data->snapshot.addr[y * (data->snapshot.size_line / 4) + data->dstx] = colour;
// printf("debug %d\n", data->snapshot.addr[y * (data->snapshot.size_line / 4) + data->dstx]);
	// mlx_put_image_to_window(data->mlx, data->win, data->snapshot.img, 0, 0);
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


void    test_render(t_cub* data)
{
    int colour;

	data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);
    
    // code here-----------------------
    
    int x = 200; // getting this requires a function. find_x(data)
    int y = 470;
    double row;
    // int p;
    
    //x remains constant. for each iteration, change y.
    // colour = create_colourcode(0, 100, 200, 200);
    for (int i=100; i<y; i++)
    {
        // printf("debug\n");
        row = 1.00 * (i-x) / (y-x) * 1024;
        // p = row;
        // printf("color %f %d %d", row, p, i);
        colour = data->texture[0].addr[(int)row * (data->snapshot.size_line / 4) + x];
        printf("color is %d\n", colour);
        data->snapshot.addr[i * (data->snapshot.size_line / 4) + x] = colour;
    }
    






// code here-----------------------

	mlx_put_image_to_window(data->mlx, data->win, data->snapshot.img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->win, data->texture[0].img, 0, 0);
    mlx_destroy_image(data->mlx, data->snapshot.img);


	mlx_hook(data->win, 2, 1L<<0, key_press, data);
	mlx_hook(data->win, 3, 1L<<1, key_release, data);
	mlx_hook(data->win, 17, 0, mlx_close, data);
	mlx_loop(data->mlx);

	mlx_destroy_display(data->mlx);
	free(data->mlx);

}
//     int src_h;
//     int dst_h;
//     int txt;

//     src_h = data->srcy1 - data->srcy0 + 1;
//     dst_h = data->dsty1 - data->dsty0 + 1;
//     txt = texture_of(data->endpt, data->ray_vector) - 1;
    
// // printf("debug %d\n", data->snapshot.addr[y * (data->snapshot.size_line / 4) + data->dstx]);