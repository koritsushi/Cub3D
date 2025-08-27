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

// int	orthogonal_solid(t_cub* data, t_pt pt)
// {
// 	if (data->dir_pt.x > 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
// 	}
// 	else if (data->dir_pt.x < 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
// 	}
// 	else if (data->dir_pt.y > 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
// 	}
// 	else if (data->dir_pt.y < 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
// 	}
// 	return (0);
// }

// int	diagonal_solid(t_cub* data, t_pt pt)
// {
// 	//if diagonal is solid || two sides are solid, return 1
// 	// else return 0
// 	if (data->dir_pt.x > 0 && data->dir_pt.y > 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
// 		printf(" OR \n");
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
// 	}
// 	else if (data->dir_pt.x > 0 && data->dir_pt.y < 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
// 		printf(" OR \n");
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
// 	}
// 	else if (data->dir_pt.x < 0 && data->dir_pt.y > 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
// 		printf(" OR \n");
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x));
// 	}
// 	else if (data->dir_pt.x < 0 && data->dir_pt.y < 0)
// 	{
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x) - 1);
// 		printf(" OR \n");
// 		printf("check cell[%d][%d]\n", (int)round(pt.y), (int)round(pt.x) - 1);
// 		printf("check cell[%d][%d]\n", (int)round(pt.y) - 1, (int)round(pt.x));
// 	}
// 	return (0);
// }

// int	pt_on_solid(t_cub* data, t_pt pt)
// {
// 	printf("pt_on_solid: running\n");

// 	if (!is_wholenum(pt.x) && !is_wholenum(pt.y))
// 	{
// 		printf("keep running, no need to check cell yet\n");
// 		return (0);
// 	}
// 	//else check for edge and diagonal cases
// 	else if (is_wholenum(pt.x) && is_wholenum(pt.y))
// 	{
// 		printf("pt is on a diagonal\n");
// 		if (fabsf(data->dir_pt.x) > PRECISION && fabsf(data->dir_pt.y) > PRECISION)
// 		{
// 			diagonal_solid(data, pt);
// 			printf("pt will move diagonally\n");
// 		}
// 		else if (fabsf(data->dir_pt.x) > PRECISION || fabsf(data->dir_pt.y) > PRECISION)
// 		{
// 			orthogonal_solid(data, pt);
// 			printf("pt will move orthogonally\n");
// 		}
// 		// both x and y == 0 is not possible, since struct initialises with a direction
// 	}
// 	else if (is_wholenum(pt.x))
// 	{
// 		if (data->dir_pt.x > 0)
// 			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x));
// 		if (data->dir_pt.x < 0)
// 			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)round(pt.x) - 1);
// 	}
// 	else if (is_wholenum(pt.y))
// 	{
// 		if (data->dir_pt.y > 0)
// 			printf("check cell[%d][%d]\n", (int)floor(pt.y), (int)floor(pt.x));
// 		if (data->dir_pt.y < 0)
// 			printf("check cell[%d][%d]\n", (int)floor(pt.y) - 1, (int)floor(pt.x));
// 	}
// 	else
// 		printf("keep running, no need to check cell yet\n");
// 	return (0);
// }
