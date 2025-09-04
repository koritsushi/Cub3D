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