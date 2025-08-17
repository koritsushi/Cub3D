/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 00:06:06 by booi              #+#    #+#             */
/*   Updated: 2025/08/18 00:06:22 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"

int cub_exec(t_cub data)
{
	printf("\e[32mcub_exec running.\n\e[0m");
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	


	mlx_destroy_display(mlx);
	free(mlx);
    return (0);
}