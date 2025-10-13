/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:21:12 by mliyuan           #+#    #+#             */
/*   Updated: 2025/10/11 17:37:41 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

void	init_p1(t_cub *data, int x, int y, char c)
{
	data->p1.x = x + 0.5;
	data->p1.y = y + 0.5;
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

void	texcol_init(t_cub *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].img = NULL;
		data->texture[i].addr = NULL;
		data->texture[i].size_line = 0;
		data->texture[i].endian = 0;
		i++;
	}
	data->c_col = 0;
	data->f_col = 0;
	data->height = 0;
	data->width = 0;
	data->map = NULL;
	data->cmap = NULL;
}

void	struct_init(t_cub *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		printf("struct_init: error creating exec.mlx\n");
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, "Cube3D");
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
	int		status;

	fd_cub = 0;
	if (argc != 2 || check_ext(&fd_cub, argv[1], ".cub") == 0)
		return (ft_error(0), 1);
	printf("./cube3D: Valid .cub extension file: %s\n", argv[1]);
	struct_init(&data);
	texcol_init(&data);
	file = read_file(fd_cub);
	printf("%s\n", file);
	if (parse_file(&data, file) == 0)
		return (free(file), ft_error(1), 1);
	printf("./cube3D: Valid Colors and Texture\n");
	free(file);
	if (parse_map(&data) == 0)
		return (ft_free(&data, 1), ft_error(2), 1);
	cub_exec(&data);
	ft_free(&data, 1);
	system("xset r on");
	return (0);
}
