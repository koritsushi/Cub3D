/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:31:37 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/11 19:31:37 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	error_init(char *err[])
{
	err[0] = "./cube3D: Usage: ./.cub3d filename.cub\n";
	err[1] = "./cube3D: Invalid texture or color!";
	err[2] = "./cube3D: Invalid Map";
}

void	ft_error(int flag)
{
	char	*err[3];

	error_init(err);
	ft_putstr_fd("./cube3D: Error!\n", 2);
	ft_putstr_fd(err[flag], 2);
}

void	ft_free(t_cub *data, int flag)
{
	int	i;

	i = 0;
	ft_free_arr((void **) data->map);
	ft_free_arr((void **) data->cmap);
	while (i < 4 && flag == 1)
		mlx_destroy_image(data->exec.mlx, data->texture[i++].img);
	free(data->exec.mlx);
}
