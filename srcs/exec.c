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
#include <math.h>

int	adjust_dir_pt(t_cub* data)
{
	return (0);
}

int	player_turn(t_cub* data, int keycode)
{
	printf("player_turn: running %d\n", keycode);
	if (keycode == KEY_LEFT)
	{
		if (data->dir_angle == 359)
			data->dir_angle = 0;
		else
			data->dir_angle++;
		printf("player_turn: left. angle is now %d\n", data->dir_angle);
	}
	else if (keycode == KEY_RIGHT)
	{
		if (data->dir_angle == 0)
			data->dir_angle = 359;
		else
			data->dir_angle--;
		printf("player_turn: right. angle is now %d\n", data->dir_angle);
	}
	adjust_dir_pt(data);
	return (0);
}

int	key_hook(int keycode, t_cub* data)
{
	printf("key_hook: executed!\n");
	if (keycode == ESC)
	{
		printf("key_hook: ESC pressed.\n");
		exit(0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_turn(data, keycode);
	else if (keycode == KEY_W || 
			keycode == KEY_S ||
			keycode == KEY_A ||
			keycode == KEY_D)
		player_turn(data, keycode);
	return (0);
}

int cub_exec(t_cub* data)
{
	printf("\e[32mcub_exec running.\n\e[0m");
	t_vars	vars;
 
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Screen name");	
	mlx_key_hook(vars.win, key_hook, data); //on key press
	//list of events to listen for
	// keypress
	// keyrealase

	mlx_loop(vars.mlx);

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
    return (0);
}