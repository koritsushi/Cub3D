/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:21:12 by mliyuan           #+#    #+#             */
/*   Updated: 2025/09/19 15:59:41 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	struct_init(t_cub *data)
{
	int	i;

	i = 0;
	data->p1.x = 0;
	data->p1.y = 0;
	data->dir_angle = 0;
	data->dir_pt.x = 0;
	data->dir_pt.y = 0;
	data->exec.mlx = NULL;
	data->exec.win = NULL;
	while (i < 4)
	{
		data->texture[i].img = NULL;
		data->texture[i].address = NULL;
		data->texture[i].line_length = 0;
		data->texture[i].endian = 0;
		i++;
	}
	data->height = 0;
	data->width = 0;
	data->map = NULL;
	data->cmap = NULL;
	data->f_col = 0;
	data->c_col = 0;
}

int	main(int argc, char **argv)
{
	t_cub	data;
	int		fd_cub;
	char	*file;
	int		i;

	fd_cub = 0;
	if (argc != 2 || check_ext(&fd_cub, argv[1], ".cub") == 0)
		ft_error();
	struct_init(&data);
	file = read_file(fd_cub);
	data.exec.mlx = mlx_init();
	if (parse_file(&data, file) == 0)
		return (1);
	free(file);
	if (parse_map(&data) == 0)
		return (ft_free_arr((void **) data.map), 1);
	i = 0;
	ft_free_arr((void **) data.map);
	while (i < 4)
		mlx_destroy_image(data.exec.mlx, data.texture[i++].img);
	free(data.exec.mlx);
	return (0);
}
