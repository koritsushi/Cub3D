/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:17:22 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/19 15:17:22 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_free_arr(void **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

int	ft_free_parsing(char **content, t_cub *data, int flags[])
{
	ft_free_arr((void **) content);
	free_tex(data, flags);
	ft_free(data, 0);
	return (0);
}

void	free_tex(t_cub *data, int flags[])
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (flags[i] == 1 || flags[i] == 2)
			mlx_destroy_image(data->mlx, data->texture[i].img);
	}
}

void	ft_free(t_cub *data, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < 4)
			mlx_destroy_image(data->mlx, data->texture[i++].img);
		ft_free_arr((void **) data->map);
		ft_free_arr((void **) data->cmap);
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
