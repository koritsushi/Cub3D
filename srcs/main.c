/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:21:12 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/15 14:57:38 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

void	struct_init(t_cub *data)
{
	data->p1.x = 1.9999;
	data->p1.y = 2.905;
	data->dir_angle = 30; //init depending on starting p1 orientation
	data->dir_pt.x = 10;
	data->dir_pt.y = -0.5;
	data->move_fwd = 0;
	data->move_back = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->turn_left = 0;
	data->turn_right = 0;
	data->map = create_dummy();
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f_col = 0;
	data->c_col = 0;
}

int	main(int argc, char **argv)
{
	t_cub	data;
	int		fd_cub;
	char	*file;

	fd_cub = 0;
	if (argc != 2 || check_cub(&fd_cub, argv[1]) == 0)
		ft_error();
	struct_init(&data);
	file = NULL;
	file = read_file(fd_cub);

	printf("file is %p\n", file);
	printf("data is %p\n", &data);

	n_of(data.map, data.p1);
	e_of(data.map, data.p1);
	s_of(data.map, data.p1);
	w_of(data.map, data.p1);
	ne_of(data.map, data.p1);
	se_of(data.map, data.p1);
	sw_of(data.map, data.p1);
	nw_of(data.map, data.p1);
	// printf("cell(%f,%f) is %c\n", data.p1.x, data.p1.y, data.map[(int)data.p1.y][(int)data.p1.x]);

	// print_arr(data.map);
	// t_pt	pt;
	// pt = snap_xy(data.p1);
	// pt = next_checkpoint(data.p1, data.dir_pt);
	// printf("next point (%f, %f)\n", pt.x, pt.y);
	// pt_on_solid(&data, data.p1);
	// cub_exec(&data);
	free(file);
	system("xset r on");
	return 0;
}
