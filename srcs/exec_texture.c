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
    int celly;

    src_h = data->srcy1 - data->srcy0 + 1;
    dst_h = data->dsty1 - data->dsty0 + 1;
    
    celly = (int)(1.0 * (y - data->dsty0) / dst_h * src_h) + data->srcy0;
    // printf("fill texture: x %d y %d celly %d \n", data->srcx, y, celly);

    colour = data->ray_texture->addr[celly * (data->snapshot.size_line / 4) + data->srcx];
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

    data->texture[i].width = width;
    data->texture[i].height = height;
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

void    update_colinfo(t_cub* data, double ratio)
{
    int x;

    // data->txt_n = get texture array number depending on NSEW
    // x = get the x co-ordinate (between 0-1) for where ray hits wall
    // data->dstx = x * S_WIDTH;
    // data->srcx = x * T_WIDTH;
    // data->srcy0 = (int)(ratio * T_HEIGHT);
    // data->srcy1 = T_HEIGHT - (int)(ratio * T_HEIGHT);
    // data->src_h = data->srcy1 - data->srcy0 + 1;
    // data->dsty0 = (int)(ratio * S_HEIGHT);
    // data->dsty1 = S_HEIGHT - (int)(ratio * S_HEIGHT);
    // data->dst_h = data->dsty1 - data->dsty0 + 1;
}

void    test_render(t_cub* data)
{
	data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);
    
    // code here-----------------------

	data->txt_n = SOUTH - 1;
	data->srcx = 0;
	data->srcy0 = 0;
	data->srcy1 = 1024;
	data->src_h = data->srcy1 - data->srcy0 + 1;
	data->dstx = 0;
	data->dsty0 = 0;
	data->dsty1 = S_HEIGHT;
	data->dst_h = data->dsty1 - data->dsty0 + 1;
    
    int x;
    int y;
    int row;
    int col;
    int colour;
    colour = create_colourcode(0, 0, 200, 200);

    x = 0;
    while (x < S_WIDTH)
    {
        row = 1.0 * x / S_WIDTH * data->texture[data->txt_n].width;
        // printf("row is %d\n", row);
        y = 0;
        while (y < S_HEIGHT)
        {
            col = 1.0 * y / data->dst_h * data->src_h;
            // printf("row %d col %d\n", row, col);
            colour = data->texture[data->txt_n].addr[col * (data->snapshot.size_line / 4) + row];
            data->snapshot.addr[y * (data->snapshot.size_line / 4) + x] = colour;
            y++;
        }
        x++;
    }
    
    //x remains constant. for each iteration, change y.
    // colour = create_colourcode(0, 100, 200, 200);
    // for (int i=100; i<y; i++)
    // {
        // printf("debug\n");
        // row = 1.00 * (i-x) / (y-x) * 1024;
        // p = row;
        // printf("color %f %d %d", row, p, i);
        // colour = data->texture[0].addr[(int)row * (data->snapshot.size_line / 4) + x];
        // printf("color is %d\n", colour);
        // data->snapshot.addr[i * (data->snapshot.size_line / 4) + x] = colour;
    // }
    

// code here-----------------------

	mlx_put_image_to_window(data->mlx, data->win, data->snapshot.img, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->win, data->texture[data->txt_n].img, 0, 0);
    mlx_destroy_image(data->mlx, data->snapshot.img);


	mlx_hook(data->win, 2, 1L<<0, key_press, data);
	mlx_hook(data->win, 3, 1L<<1, key_release, data);
	mlx_hook(data->win, 17, 0, mlx_close, data);
	mlx_loop(data->mlx);

	mlx_destroy_display(data->mlx);
	free(data->mlx);

}