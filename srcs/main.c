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
	int	i;

	i = 0;
	init_p1(data, 'N');
	data->mlx = mlx_init();
	if (!data->mlx)
		printf("struct_init: error creating exec.mlx\n");
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, "Screen name");
	while (i < 4)
	{
		data->texture[i].img = NULL;
		data->texture[i].addr = NULL;
		data->texture[i].size_line = 0;
		data->texture[i].endian = 0;
		i++;
	}
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->c_col = create_colourcode(0, 100, 0, 0);
	data->f_col = create_colourcode(0, 0, 0, 200);

	data->height = 0;
	data->width = 0;
	data->map = NULL;
	data->cmap = NULL;

	update_cameraplane(data);
	data->mfwd = 0;
	data->mback = 0;
	data->mleft = 0;
	data->mright = 0;
	data->tleft = 0;
	data->tright = 0;
	data->step = get_step(data);
}

int	main(int argc, char **argv)
{
	t_cub	data;
	int		fd_cub;
	char	*file;

	fd_cub = 0;
	if (argc != 2 || check_ext(&fd_cub, argv[1], ".cub") == 0)
		return (ft_error(0), 1);
	struct_init(&data);
	printf("datamlx %p\n", data.mlx);
	file = read_file(fd_cub);
	printf("./cube3D: Valid ./.cub extension file\n");
	printf("./cube3D: Initialise program\n");
	if (parse_file(&data, file) == 0)
		return (ft_free(&data, 0), ft_error(1), 1);
	printf("./cube3D: Valid Colors and Texture\n");
	if (parse_map(&data) == 0)
		return (ft_free(&data, 1), ft_error(2), 1);
	printf("./cube3D: Valid Map\n");
	printf("datamlx %p\n", data.mlx);
	// init_texture(&data, "wolfenstein/wood.xpm", 0);
	// init_texture(&data, "wolfenstein/mossy.xpm", 1);
	// init_texture(&data, "wolfenstein/eagle.xpm", 2);
	// init_texture(&data, "wolfenstein/blue_stone.xpm", 3);
	cub_exec(&data);
	free(file);
	ft_free(&data, 1);
	system("xset r on");
	return (0);
}
