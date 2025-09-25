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

void	init_p1(t_cub* data, char c)
{
	data->p1.x = 3.5;
	data->p1.y = 3.5;
	if (c == 'N')
		data->dir_angle = 90;
	else if (c == 'S')
		data->dir_angle = 270;
	else if (c == 'E')
		data->dir_angle = 0;
	else if (c == 'W')
		data->dir_angle = 180;
	// data->dir_angle = 45;
	data->dir_pt = vector_of(data->dir_angle);
	// printf("init_p1: dir_angle %f dir_pt (%f, %f)\n", data->dir_angle, data->dir_pt.x, data->dir_pt.y);
}

void	struct_init(t_cub *data)
{
	init_p1(data, 'W');
	update_cameraplane(data);
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

	data->step = get_step(data);

	data->mlx = mlx_init();
	if (!data->mlx)
		printf("struct_init: error creating exec.mlx\n");
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, "Screen name");	
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

	init_texture(&data, "blue.xpm", 0);
	init_texture(&data, "brick.xpm", 1);
	init_texture(&data, "stone.xpm", 2);
	init_texture(&data, "blue.xpm", 3);
	test_render(&data);
	// cub_exec(&data);
	// colour_col(&data, 0);
	// fill_texture(&data, 0);
	// render_snapshot(&data);
	free(file);
	system("xset r on");
	return 0;
}
