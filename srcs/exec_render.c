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
	data->img.img = mlx_new_image(data->vars.mlx, 1, S_HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.size_line, &data->img.endian);
	//fill in 3 column parts
    mlx_destroy_image(data->vars.mlx, data->img.img);
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