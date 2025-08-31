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
	void* img;

	img = mlx_new_image(data->vars.mlx, 1, S_HEIGHT);
	//fill in 3 column parts
    return (0);

}

int render_screen()
{
    int i;

    i = 0;
    while (i < S_WIDTH)
    {
        // render_col(i);
        i++;
    }
    return (0);
}