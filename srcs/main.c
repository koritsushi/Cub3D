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
	data->p1.x = 3.5;
	data->p1.y = 3.5;
	data->dir_angle = 45; //init depending on starting p1 orientation
	data->dir_pt.x = 0.1;
	data->dir_pt.y = -0.1;
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
	data->vars.mlx = mlx_init();
	if (!data->vars.mlx)
		printf("struct_init: error creating exec.mlx\n");
	data->vars.win = mlx_new_window(data->vars.mlx, S_WIDTH, S_HEIGHT, "Screen name");	
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

	cub_exec(&data);
	// render_snapshot(&data);
	free(file);
	system("xset r on");
	return 0;
}
