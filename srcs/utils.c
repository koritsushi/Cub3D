/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:51:42 by booi              #+#    #+#             */
/*   Updated: 2025/08/21 22:51:46 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

t_pt    vector_of(float angle);

t_pt    vector_of(float angle)
{
    t_pt    p;

	p.x = cos(angle / 180 * M_PI) * MOVE_SPEED;
	p.y = sin(angle / 180 * M_PI) * MOVE_SPEED * (-1);
    return (p);
}