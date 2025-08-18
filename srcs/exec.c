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

typedef struct	s_vars
{
	void*	mlx;
	void*	win;

}				t_vars;

int	key_hook(int keycode, t_vars* vars)
{
	printf("key_hook: executed!\n");
	if (keycode == ESC)
	{
		printf("key_hook: ESC pressed.\n");
		exit(0);
	}
	return (0);
}

int cub_exec(t_cub data)
{
	printf("\e[32mcub_exec running.\n\e[0m");
	void	*mlx;
	void	*win;
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Screen name");	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	mlx_destroy_display(mlx);
	free(mlx);
    return (0);
}