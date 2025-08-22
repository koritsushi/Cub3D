/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_orthocell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:37:43 by booi              #+#    #+#             */
/*   Updated: 2025/08/22 09:37:44 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"

t_pt    snap_xy(t_pt pt);
char    n_of(char** map, t_pt pt);

t_pt    snap_xy(t_pt pt)
{
    if (is_wholenum(pt.x))
        pt.x = roundf(pt.x);
    if (is_wholenum(pt.y))
        pt.y = roundf(pt.y);
    printf("snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
    pt.x = floorf(pt.x);
    pt.y = floorf(pt.y);
    printf("snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
    return (pt);
}

char    n_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);

    
    return (0);
}