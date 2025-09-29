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

int		mlx_close(int keycode, t_cub *data);
void	update_movement(t_cub *data, int keycode, int state);
int		key_press(int keycode, t_cub *data);
int		key_release(int keycode, t_cub *data);
int		cub_exec(t_cub *data);

int	mlx_close(int keycode, t_cub *data)
{
	printf("mlx_close: keycode %d, data %p\n", keycode, data);
	exit(0);
}

void	update_movement(t_cub *data, int keycode, int state)
{
	if (keycode == KEY_LEFT)
		data->tleft = state;
	else if (keycode == KEY_RIGHT)
		data->tright = state;
	else if (keycode == KEY_W)
		data->mfwd = state;
	else if (keycode == KEY_S)
		data->mback = state;
	else if (keycode == KEY_A)
		data->mleft = state;
	else if (keycode == KEY_D)
		data->mright = state;
}

int	key_press(int keycode, t_cub *data)
{
	if (keycode == ESC)
	{
		printf("key_hook: ESC pressed.\n");
		system("xset r on");
		exit(0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_W
		|| keycode == KEY_S
		|| keycode == KEY_A
		|| keycode == KEY_D)
		update_movement(data, keycode, 1);
	return (0);
}

int	key_release(int keycode, t_cub *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_W
		|| keycode == KEY_S
		|| keycode == KEY_A
		|| keycode == KEY_D)
		update_movement(data, keycode, 0);
	return (0);
}

int	cub_exec(t_cub *data)
{
	void	*img;

	system("xset r off");
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0, mlx_close, data);
	mlx_loop_hook(data->mlx, update_state, data);
	mlx_loop(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (0);
}
