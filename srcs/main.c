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

void	init_p1(t_cub *data, char c)
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
	data->dir_pt = vector_of(data->dir_angle);
}

void	struct_init(t_cub *data)
{
	init_p1(data, 'N');
	update_cameraplane(data);
	data->mfwd = 0;
	data->mback = 0;
	data->mleft = 0;
	data->mright = 0;
	data->tleft = 0;
	data->tright = 0;
	data->map = create_dummy();
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->c_col = create_colourcode(0, 100, 0, 0);
	data->f_col = create_colourcode(0, 0, 0, 200);
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
	init_texture(&data, "wolfenstein/wood.xpm", 0);
	init_texture(&data, "wolfenstein/mossy.xpm", 1);
	init_texture(&data, "wolfenstein/eagle.xpm", 2);
	init_texture(&data, "wolfenstein/blue_stone.xpm", 3);
	cub_exec(&data);
	free(file);
	system("xset r on");
	return (0);
}
