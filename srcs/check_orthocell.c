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

char    cell_beside_ipt(char** map, t_pt pt, int dir);
char    cell_beside_wpt(char** map, t_pt pt, int dir);
char    cell_beside_bpt(char** map, t_pt pt, int dir);
char    cell_beside(char** map, t_pt pt, int dir);


char    cell_beside_ipt(char** map, t_pt pt, int dir)
{
    //pt is on intersection
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    printf("%d\n", dir);

    if (dir == NORTHEAST || dir == SOUTHEAST)
        pt.x = floorf(pt.x);
    else if (dir == NORTHWEST || dir == SOUTHWEST)
        pt.x = floorf(pt.x) - 1;
    else
        pt.x = -1;

    if (dir == SOUTHWEST || dir == SOUTHEAST)
        pt.y = floorf(pt.y);
    else if (dir == NORTHWEST || dir == NORTHEAST)
        pt.y = floorf(pt.y) - 1;
    else
        pt.y = -1;

    if (pt.x == -1 || pt.y == -1)
        return (0);
    // printf("n_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (map[(int)pt.y][(int)pt.x]);
}

char    cell_beside_bpt(char** map, t_pt pt, int dir)
{
    //pt is on border
    // printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    if (is_wholenum(pt.x) && !is_wholenum(pt.y))
    {
        if (dir == NORTHEAST || dir == EAST || dir == SOUTHEAST)
            pt.x = floorf(pt.x);
        else if (dir == NORTHWEST || dir == WEST || dir == SOUTHWEST)
            pt.x = floorf(pt.x) - 1;
        else
            pt.x = -1;
        pt.y = floorf(pt.y);
    }
    else if (!is_wholenum(pt.x) && is_wholenum(pt.y))
    {
        pt.x = floorf(pt.x);
        if (dir == SOUTHWEST || dir == SOUTH || dir == SOUTHEAST)
            pt.y = floorf(pt.y);
        else if (dir == NORTHWEST || dir == NORTH || dir == NORTHEAST)
            pt.y = floorf(pt.y) - 1;
        else
            pt.y = -1;
    }
    if (pt.x == -1 || pt.y == -1)
        return (0);
    // printf("n_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (map[(int)pt.y][(int)pt.x]);
}

char    cell_beside_wpt(char** map, t_pt pt, int dir)
{
    //pt is within a cell
    // printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    if (dir == NORTHWEST || dir == WEST || dir == SOUTHWEST)
        pt.x = floorf(pt.x) - 1;
    else if (dir == HERE || dir == NORTH || dir == SOUTH)
        pt.x = floorf(pt.x);
    else if (dir == NORTHEAST || dir == EAST || dir == SOUTHEAST)
        pt.x = floorf(pt.x) + 1;

    if (dir == NORTHWEST || dir == NORTH || dir == NORTHEAST)
        pt.y = floorf(pt.y) - 1;
    else if (dir == WEST || dir == HERE || dir == EAST)
        pt.y = floorf(pt.y);
    else if (dir == SOUTHWEST || dir == SOUTH || dir == SOUTHEAST)
        pt.y = floorf(pt.y) + 1;
    // printf("n_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (map[(int)pt.y][(int)pt.x]);
}

char    cell_beside(char** map, t_pt pt, int dir)
{
    //only if pt is not on border/intersection
    pt = snap_xy(pt);
    if (is_wholenum(pt.x) && is_wholenum(pt.y))
    {
        return (cell_beside_ipt(map, pt, dir));
    }
    else if (!is_wholenum(pt.x) && !is_wholenum(pt.y))
        return (cell_beside_wpt(map, pt, dir));
    else if (is_wholenum(pt.x) || is_wholenum(pt.y))
        return (cell_beside_bpt(map, pt, dir));
    return (0);
}

int    is_endpoint_ipt(char** map, t_pt pt, int dir)
{
    if (dir == NORTH)
        return (is_solid(cell_beside_ipt(map, pt, NORTHWEST)) && is_solid(cell_beside_ipt(map, pt, NORTHEAST)));
    else if (dir == EAST)
        return (is_solid(cell_beside_ipt(map, pt, NORTHEAST)) && is_solid(cell_beside_ipt(map, pt, SOUTHEAST)));
    else if (dir == SOUTH)
        return (is_solid(cell_beside_ipt(map, pt, SOUTHWEST)) && is_solid(cell_beside_ipt(map, pt, SOUTHEAST)));
    else if (dir == WEST)
        return (is_solid(cell_beside_ipt(map, pt, NORTHWEST)) && is_solid(cell_beside_ipt(map, pt, SOUTHWEST)));
    else if (dir == NORTHEAST)
        return (is_solid(cell_beside_ipt(map, pt, dir)) ||
            (is_solid(cell_beside_ipt(map, pt, NORTHWEST)) && is_solid(cell_beside_ipt(map, pt, SOUTHEAST))));
    else if (dir == SOUTHEAST)
        return (is_solid(cell_beside_ipt(map, pt, dir)) ||
            (is_solid(cell_beside_ipt(map, pt, NORTHEAST)) && is_solid(cell_beside_ipt(map, pt, SOUTHWEST))));
    else if (dir == SOUTHWEST)
        return (is_solid(cell_beside_ipt(map, pt, dir)) ||
            (is_solid(cell_beside_ipt(map, pt, NORTHWEST)) && is_solid(cell_beside_ipt(map, pt, SOUTHEAST))));
    else if (dir == NORTHWEST)
        return (is_solid(cell_beside_ipt(map, pt, dir)) ||
            (is_solid(cell_beside_ipt(map, pt, SOUTHWEST)) && is_solid(cell_beside_ipt(map, pt, NORTHEAST))));
    return (0);
}

int    is_endpoint(char** map, t_pt pt, int dir)
{
    pt = snap_xy(pt);
    if (is_wholenum(pt.x) && is_wholenum(pt.y))
    {
        printf("is_endpoint pt (%f, %f)\n", pt.x, pt.y);
        return is_endpoint_ipt(map, pt, dir); 
    }
    else if (is_wholenum(pt.x) || is_wholenum(pt.y))
    {
        printf("is_endpoint pt (%f, %f)\n", pt.x, pt.y);
        return (is_solid(cell_beside_bpt(map, pt, dir)));
    }
    else
    {
        printf("is_endpoint error: checkpoint is not on a cell border\n");
        return (-1);
    }
}

//assume pt is on corner 
char is_solidcpt(char** map, t_pt pt, int dir)
{

}