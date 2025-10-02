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

char    ne_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) + 1;
    pt.y = floorf(pt.y) - 1;
    printf("ne_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}

char    se_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) + 1;
    pt.y = floorf(pt.y) + 1;
    printf("se_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}

char    sw_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) - 1;
    pt.y = floorf(pt.y) + 1;
    printf("sw_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}

char    nw_of(char** map, t_pt pt)
{
    pt = snap_xy(pt);
    printf("     pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    pt.x = floorf(pt.x) - 1;
    pt.y = floorf(pt.y) - 1;
    printf("nw_of pt(%f,%f) is %c\n", pt.x, pt.y, map[(int)pt.y][(int)pt.x]);
    return (0);
}

// given a border pt and a vector, is the pt running into a solid? 1 yes, 0 no
int		is_wallhit(t_pt pt, t_pt vector, char** map)
{
	t_pt	temp;

	temp = snap_xy(pt);
	if (!is_wholenum(pt.x) && !is_wholenum(pt.y))
	{
		printf("point must be on a cell border.\n");
		return (-1);
	}
	if (is_wholenum(pt.x) && is_wholenum(pt.y))
	{
		printf("pt is on a corner\n");
		return (0);
	}
	else if (is_wholenum(pt.x))
	{
	
		// cell_beside(map, pt, direction_of(vector));
		// gives the char of the cell beside pt
		if (is_solid(cell_beside(map, pt, direction_of(vector))))
			return (1);

		if ((vector.x > 0 && is_solid(map[(int)floorf(temp.y)][(int)temp.x])) ||
			(vector.x < 0 && is_solid(map[(int)floorf(temp.y)][(int)temp.x - 1])))
			return (1);

	}
	else if (is_wholenum(pt.y))
	{
		if ((vector.y > 0 && is_solid(map[(int)floorf(temp.y)][(int)temp.x])) ||
			(vector.y < 0 && is_solid(map[(int)floorf(temp.y) - 1][(int)temp.x - 1])))
			return (1);
	}
	return (0);
}

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
int	orthogonal_solid(t_cub *data, t_pt pt)
{
	if (data->dir_pt.x > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.x < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
	}
	else if (data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	return (0);
}

int	diagonal_solid(t_cub *data, t_pt pt)
{
	//if diagonal is solid || two sides are solid, return 1
	// else return 0
	if (data->dir_pt.x > 0 && data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	else if (data->dir_pt.x > 0 && data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
	}
	else if (data->dir_pt.x < 0 && data->dir_pt.y > 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
	}
	else if (data->dir_pt.x < 0 && data->dir_pt.y < 0)
	{
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
		printf(" OR \n");
		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
	}
	return (0);
}

int	pt_on_solid(t_cub *data, t_pt pt)
{
	printf("pt_on_solid: running\n");

	if (!is_wholenum(pt.x) && !is_wholenum(pt.y))
	{
		printf("keep running, no need to check cell yet\n");
		return (0);
	}
	//else check for edge and diagonal cases
	else if (is_wholenum(pt.x) && is_wholenum(pt.y))
	{
		printf("pt is on a diagonal\n");
		if (fabsf(data->dir_pt.x) > PRECISION && fabsf(data->dir_pt.y) > PRECISION)
		{
			diagonal_solid(data, pt);
			printf("pt will move diagonally\n");
		}
		else if (fabsf(data->dir_pt.x) > PRECISION || fabsf(data->dir_pt.y) > PRECISION)
		{
			orthogonal_solid(data, pt);
			printf("pt will move orthogonally\n");
		}
		// both x and y == 0 is not possible, since struct initialises with a direction
	}
	else if (is_wholenum(pt.x))
	{
		if (data->dir_pt.x > 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x));
		if (data->dir_pt.x < 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x) - 1);
	}
	else if (is_wholenum(pt.y))
	{
		if (data->dir_pt.y > 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)floor(pt.x));
		if (data->dir_pt.y < 0)
			printf("check cell[%d][%d]\n", (int)floor(pt.y) - 1, (int)floor(pt.x));
	}
	else
		printf("keep running, no need to check cell yet\n");
	return (0);
}

void	player_move(t_cub *data, char dir)
{
	if (dir == 'f' && is_clear(data))
	{
		data->p1.x += (data->dir_pt.x * MOVE_SPEED);
		data->p1.y += (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'b' && is_clear(data))
	{
		data->p1.x -= (data->dir_pt.x * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'l' && is_clear(data))
	{
		data->p1.x += (data->dir_pt.y * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.x * MOVE_SPEED);
	}
	else if (dir == 'r' && is_clear(data))
	{
		data->p1.x -= (data->dir_pt.y * MOVE_SPEED);
		data->p1.y += (data->dir_pt.x * MOVE_SPEED);
	}
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}

src in inside cell, or on border but verified passable
t_pt	movement1(t_pt src, t_pt vector, char** map)
{
	t_pt	check;
	t_pt	dst;

	check = next_checkpoint(src, vector);
	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);

	if (d_betw(src, check) >= d_betw(src, dst))
		return (dst);
	else
	{
		vector.x = dst.x - check.x;  
		vector.y = dst.y - check.y;  
		return (dst_of2(check, vector, map));
	}
}

src is on a cell border
t_pt	movement2(t_pt src, t_pt vector, char** map)
{
	if (!is_stop(map, src, vector))
		return movement1(src, vector, map);
	else if (is_bordering(src) == 1) //vside
	{
		vector.x = 0;
		printf("vector: %f,%f\n", src.x, src.y);
		return movement1(src, vector, map);
		//need to add the x vector back in the next cycle
	}
	else if (is_bordering(src) == 2) //hside
	{
		vector.y = 0;
		return movement1(src, vector, map);
		//need to add the y vector back in the next cycle
	}
	else if (is_bordering(src) == 3) //corner
		return (src);
	else
		return (src);
}

t_pt	dst_of2(t_pt src, t_pt vector, char** map)
{
	t_pt	check;
	t_pt	dst;
	t_pt	temp;

	check = next_checkpoint(src, vector);
	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);
	temp.x = 0;
	temp.y = 0;
	printf("dst_of: check (%f,%f)\n", check.x, check.y);
	printf("dst_of: vector (%f,%f)\n", vector.x, vector.y);
	printf("dst_of: d_betw(%f), d_betw(%f)\n", d_betw(src, check), d_betw(src, dst));
	if (is_bordering(src))
	{ // 2
		if (!is_stop(map, src, vector))
			return movement1(src, vector, map);
		else if (is_bordering(src) == 1) //vside
		{
			if (vector.x > 0)
				src.x -= (1.05 * PRECISION);
			else if (vector.x < 0)
				src.x += (1.05 * PRECISION); 
			vector.x = 0;
			return movement1(src, vector, map);
			//need to add the x vector back in the next cycle
		}
		else if (is_bordering(src) == 2) //hside
		{
			if (vector.y > 0)
				src.y -= (1.05 * PRECISION);
			else if (vector.y < 0)
				src.y += (1.05 * PRECISION); 
			vector.y = 0;
			return movement1(src, vector, map);
			//need to add the y vector back in the next cycle
		}
		else if (is_bordering(src) == 3) //corner
		{
			if (vector.x > 0)
				src.x -= (4 * PRECISION);
			else if (vector.x < 0)
				src.x += (4 * PRECISION); 
			if (vector.y > 0)
				src.y -= (4 * PRECISION);
			else if (vector.y < 0)
				src.y += (4 * PRECISION); 
			vector.y = 0;
			return (src);
		}
		else
			return (src);
	}
	else
		return movement1(src, vector, map);
}

t_pt	dst_of(t_pt src, t_pt vector, char** map)
{
	t_pt	dst;
	t_pt	check;
	t_pt	temp;

	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);
	check = next_checkpoint(src, vector);
	temp.x = 0;
	temp.y = 0;
	printf("dst_of: check (%f,%f)\n", check.x, check.y);
	printf("dst_of: d_betw(%f), d_betw(%f)\n", d_betw(src, check), d_betw(src, dst));
	if (is_bordering(src) && is_stop(map, src, vector))
	{
		temp.x = dst.x - src.x;
		temp.y = 0; 
		if (is_stop(map, src, temp))
			dst.x = src.x;
		temp.y = dst.y - src.y;
		temp.x = 0; 
		if (is_stop(map, src, temp))
			dst.y = src.y;
		return (dst);
	}
	else if (d_betw(src, check) < d_betw(src, dst))
	{
		printf("dst_of: in loop\n");
		if (is_stop(map, check, vector))
		{
			temp.x = dst.x - check.x;
			temp.y = 0; 
			if (is_stop(map, check, temp))
				dst.x = check.x;
			temp.y = dst.y - check.y;
			temp.x = 0; 
			if (is_stop(map, check, temp))
				dst.y = check.y;
			return (dst);
		}
		else
			return (dst);
	}
	return (dst);
}


//pt should be on border
int	is_stop(char** map, t_pt pt, t_pt vector)
{
	int		x;
	int		y;
	t_pt	temp;

	temp = snap_xy(pt);
	x = floorf(temp.x);
	y = floorf(temp.y);
	temp.x = x;
	temp.y = y;
	if (is_bordering(pt) == 1 || is_bordering(pt) == 2)
		return (check_spt(map, temp, vector, is_bordering(pt)));
	else if (is_bordering(pt) == 3)
	{
		if (direction_of(vector) <= 4)
			return(check_ocpt(map, x, y, vector));
		else if (direction_of(vector) <= 8)
			return(check_dcpt(map, x, y, vector));
	}
	return (-1);
}


int	check_spt(char** map, t_pt pt, t_pt vector, int side)
{
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (side == 1)
	{
		if (vector.x > 0)
			return (is_solid(map[y][x]));
		else if (vector.x < 0)
			return (is_solid(map[y][x - 1]));
		else
			return (0);
	}
	else if (side == 2)
	{
		if (vector.y > 0)
			return (is_solid(map[y][x]));
		else if (vector.y < 0)
			return (is_solid(map[y - 1][x]));
		else
			return (0);
	}
	else
		return (-1);
}

int	check_ocpt(char** map, int x, int y, t_pt vector)
{
	if (direction_of(vector) == NORTH)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x])));
	else if (direction_of(vector) == EAST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x])) ||
				(is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])));
	else if (direction_of(vector) == SOUTH)
		return ((is_solid(map[y][x]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y][x])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y - 1][x])));
	else if (direction_of(vector) == WEST)
		return ((is_solid(map[y][x - 1]) && is_solid(map[y - 1][x - 1])) ||
				(is_solid(map[y][x - 1]) && is_solid(map[y - 1][x])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x - 1])) ||
				(is_solid(map[y - 1][x - 1]) && is_solid(map[y][x])));
	else
		return (-1);
}

int	check_dcpt(char** map, int x, int y, t_pt vector)
{
	if (direction_of(vector) == NORTHWEST)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				is_solid(map[y - 1][x - 1]));
	else if (direction_of(vector) == NORTHEAST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				is_solid(map[y - 1][x]));
	else if (direction_of(vector) == SOUTHEAST)
		return ((is_solid(map[y - 1][x]) && is_solid(map[y][x - 1])) ||
				is_solid(map[y][x]));
	else if (direction_of(vector) == SOUTHWEST)
		return ((is_solid(map[y][x]) && is_solid(map[y - 1][x - 1])) ||
				is_solid(map[y][x - 1]));
	else
		return (-1);
}

void	player_move(t_cub *data, char dir)
{
	printf("player_move: current p1 (%f, %f)\n", data->p1.x, data->p1.y);
	if (dir == 'f')
		data->p1 = dst_of3(data, vector_of(data->dir_angle));
	else if (dir == 'b')
		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 180, 360)));
	else if (dir == 'l')
		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 90, 360)));
	else if (dir == 'r')
		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle - 90, 360)));
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}

int	update_state(t_cub *data)
{
	usleep(100000);
	// printf("update_state: running\n");
	if (!(data->turn_left && data->turn_right) && (data->turn_left || data->turn_right))
		player_turn(data);
	if (data->move_fwd && !data->move_back)
		player_move(data, 'f');
	if (data->move_back && !data->move_fwd)
		player_move(data, 'b');
	if (data->move_left && !data->move_right)
		player_move(data, 'l');
	if (data->move_right && !data->move_left)
		player_move(data, 'r');
	// render_snapshot(data);
	return (0);
}

float adj_dist(t_cub *data, int x)
{
    float   angle_inc;
    float   angle;
    t_pt    endpt;
    float   dist;

    angle_inc = (float)FOV / (float)S_WIDTH;
    angle = mod_angle(data->dir_angle + (FOV / 2) - (x * angle_inc), 360);
    // angle_inc = 1.00000 / (S_WIDTH / 2) / (S_WIDTH / 2) * FOV;
    // angle = mod_angle(data->dir_angle + (FOV / 2) - (float)(nb_units(x) * angle_inc), 360);
    endpt = end_point(data, data->p1, vector_of(angle));
    return d_fisheye(data->p1, endpt, angle_diff(angle, data->dir_angle));
}

void    test_render(t_cub *data)
{
	data->snapshot.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
    data->snapshot.addr = (int*)mlx_get_data_addr(data->snapshot.img, &data->snapshot.bpp, &data->snapshot.size_line, &data->snapshot.endian);
    
    // code here-----------------------

	data->txt_n = NORTH - 1;
	data->srcx = 0;
	data->srcy0 = 0;
	data->srcy1 = 63;
	data->src_h = data->srcy1 - data->srcy0 + 1;
	data->dstx = 0;
	data->dsty0 = 0;
	data->dsty1 = S_HEIGHT - 1;
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
        row = ceil(1.0 * x / S_WIDTH * data->texture[data->txt_n].width) - 1;
        if (row < 0)
            row = 0;
        // printf("row is %d\n", row);
        y = 0;
        while (y < S_HEIGHT)
        {
            col = ceil(1.0 * y / data->dst_h * data->src_h) - 1;
            if (col < 0)
                col = 0;
            colour = data->texture[data->txt_n].addr[col * (data->texture[data->txt_n].size_line / 4) + row];
            // printf("xy(%d, %d) (%d, %d) col%d", x, y, row, col, colour);
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


void    update_colinfo(t_cub *data, double ratio)
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


//processing texture
int	side_to_use(t_pt endpt, t_pt vector)
{
	if (is_bordering(endpt) == 1 && vector.x > 0)
		return (WEST);
	else if (is_bordering(endpt) == 1 && vector.x < 0)
		return (EAST);
	else if (is_bordering(endpt) == 2 && vector.y > 0)
		return (NORTH);
	else if (is_bordering(endpt) == 2 && vector.y < 0)
		return (SOUTH);
	else if (is_bordering(endpt) == 3)
		return (NORTH); // this is arbitrary. need to fix later
	else
		return (-1);
}


int	dist(t_cub *data)
{
	int	i;
	double	angle;
	double	step;

	i = 0;
	step = get_step(data);
	while (i <= S_WIDTH)
	{
		angle = atan((S_WIDTH / 2 - i) * step) / M_PI * 180;
		angle = mod_angle(data->dir_angle + angle, 360);
		// printf("angle is %f\n", angle);
		i++;
	}
	return (0);
}

double	get_ratio(t_cub *data, int i)
{
	double	angle;
	double	dist;
	double	factor;
	double	d_cam;
	double	d_wall;

	angle = atan((S_WIDTH / 2 - i) * data->step);
	d_cam = fabs(D_CAMERA / cos(angle));
	d_wall = d_betw(data->p1, end_point(data, data->p1, data->ray_vector));
	if (d_cam >= d_wall)
		return (-d_wall / d_cam);		
	else
	{
		factor = d_cam / sqrt(ft_power(data->ray_vector.x, 2) + ft_power(data->ray_vector.y, 2));
		data->ray_start.x = data->p1.x + factor * data->ray_vector.x;
		data->ray_start.y = data->p1.y + factor * data->ray_vector.y;
		dist = d_betw(data->ray_start, end_point(data, data->ray_start, data->dir_pt));
		dist = data->d_ray;
		// dist = d_fisheye(ray_start, end_point(data, ray_start, data->dir_pt), fabs(angle));
		if (dist >= HORIZON)
			return (0.5);
		else
			return (dist / HORIZON * 0.5);
	}
}

//find camera start point
// if d_camerapoint > d_endpoint, LOS is blocked - render all wall
// else count camerapoint, dir_pt vector to endpoint to get distance (no need fisheye) -> this gives distance
// use distance to count ratio
// increment by step to render next column

int	nb_units(int x)
{
	int	p;
	int	i;
	int	mid;

	mid = S_WIDTH / 2;
	p = mid;
	i = -1;
	if (x < mid)
	{
		while (++i < x)
			p += (mid - i - 1);
	}
	else
	{
		i = mid - 1;
		p = mid * (mid + 1) / 2;
		while (++i < x)
			p += (i - mid);
	}
	return (p);
}

float	angle_diff(float angle1, float angle2)
{
	float	p;

	p = fabs(angle1 - angle2);
	if (p > 180)
		return (360 - p);
	return (p);
}