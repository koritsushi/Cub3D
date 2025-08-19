/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 00:06:06 by booi              #+#    #+#             */
/*   Updated: 2025/08/19 11:16:42 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

int		mlx_close(int keycode, t_vars *vars);
void	update_movement(t_cub* data, int keycode, int state);
int		key_press(int keycode, t_cub* data);
int		key_release(int keycode, t_cub* data);
int 	cub_exec(t_cub* data);

int	mlx_close(int keycode, t_vars *vars)
{
	printf("mlx_close: keycode %d, vars %p\n", keycode, vars);
	exit(0);
}


void	update_movement(t_cub* data, int keycode, int state)
{
	if (keycode == KEY_LEFT)
		data->turn_left = state;
	else if (keycode == KEY_RIGHT)
		data->turn_right = state;
	else if (keycode == KEY_W)
		data->move_fwd = state;
	else if (keycode == KEY_S)
		data->move_back = state;
	else if (keycode == KEY_A)
		data->move_left = state;
	else if (keycode == KEY_D)
		data->move_right = state;
	printf("WASD key is %d%d%d%d\n", data->move_fwd, data->move_back, data->move_left, data->move_right);
}

int	key_press(int keycode, t_cub* data)
{
	printf("key_press: executed!\n");
	if (keycode == ESC)
	{
		printf("key_hook: ESC pressed.\n");
		system("xset r on");
		exit(0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
			keycode == KEY_W || 
			keycode == KEY_S ||
			keycode == KEY_A ||
			keycode == KEY_D)
		update_movement(data, keycode, 1);
	return (0);
}

int	key_release(int keycode, t_cub* data)
{
	printf("key_release: executed!\n");
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
			keycode == KEY_W || 
			keycode == KEY_S ||
			keycode == KEY_A ||
			keycode == KEY_D)
		update_movement(data, keycode, 0);
	return (0);
}

int cub_exec(t_cub* data)
{
	system("xset r off");
	printf("\e[32mcub_exec running.\n\e[0m");
	t_vars	vars;
 
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Screen name");	
	// mlx_key_hook(vars.win, key_press, data);
	mlx_hook(vars.win, 2, 1L<<0, key_press, data);
	mlx_hook(vars.win, 3, 1L<<1, key_release, data);
	mlx_hook(vars.win, 17, 0, mlx_close, &vars);

	mlx_loop_hook(vars.mlx, update_state, data);

	mlx_loop(vars.mlx);

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
    return (0);
}
