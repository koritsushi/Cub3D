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