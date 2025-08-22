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
char    e_of(char** map, t_pt pt);
char    s_of(char** map, t_pt pt);
char    w_of(char** map, t_pt pt);

t_pt    snap_xy(t_pt pt)
{
    printf("before snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
    if (is_wholenum(pt.x))
        pt.x = roundf(pt.x);
    if (is_wholenum(pt.y))
        pt.y = roundf(pt.y);
    printf("after snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
    // pt.x = floorf(pt.x);
    // pt.y = floorf(pt.y);
    // printf("snap_xy: pt is (%f, %f)\n", pt.x, pt.y);
    return (pt);
}

char    n_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x);
    pt.y = floorf(pt.y) - 1;
    printf("n_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}

char    e_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) + 1;
    pt.y = floorf(pt.y);
    printf("e_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}
char    s_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x);
    pt.y = floorf(pt.y) + 1;
    printf("s_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}
char    w_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) - 1;
    pt.y = floorf(pt.y);
    printf("w_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}