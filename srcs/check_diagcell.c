/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diagcell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:37:53 by booi              #+#    #+#             */
/*   Updated: 2025/08/22 09:37:54 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"

// char    ne_of(char** map, t_pt pt);
// char    se_of(char** map, t_pt pt);
// char    sw_of(char** map, t_pt pt);
// char    nw_of(char** map, t_pt pt);

// char    ne_of(char** map, t_pt pt)
// {
//     pt = snap_xy(pt);
//     printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     pt.x = floorf(pt.x) + 1;
//     pt.y = floorf(pt.y) - 1;
//     printf("ne_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     return (0);
// }

// char    se_of(char** map, t_pt pt)
// {
//     pt = snap_xy(pt);
//     printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     pt.x = floorf(pt.x) + 1;
//     pt.y = floorf(pt.y) + 1;
//     printf("se_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     return (0);
// }

// char    sw_of(char** map, t_pt pt)
// {
//     pt = snap_xy(pt);
//     printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     pt.x = floorf(pt.x) - 1;
//     pt.y = floorf(pt.y) + 1;
//     printf("sw_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     return (0);
// }

// char    nw_of(char** map, t_pt pt)
// {
//     pt = snap_xy(pt);
//     printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     pt.x = floorf(pt.x) - 1;
//     pt.y = floorf(pt.y) - 1;
//     printf("nw_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
//     return (0);
// }