/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:21:12 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 22:59:50 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	struct_init(t_cub *data)
{
	data->p1.x = 0;
	data->p1.y = 0;
	data->dir_angle = 0;
	data->dir_pt.x = 0;
	data->dir_pt.y = 0;
	data->map = NULL;
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
	int		checker;
	char	*file;

	fd_cub = 0;
	if (argc != 2 || check_ext(&fd_cub, argv[1], ".cub") == 0)
		ft_error();
	struct_init(&data);
	file = read_file(fd_cub);
	checker = parse_file(&data, file);
	if (checker == 0)
		return (1);
	printf("%d\n", data.f_col);
	printf("%d\n", data.c_col);
	free(file);
	return 0;
}
