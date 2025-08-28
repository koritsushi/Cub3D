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
	// printf("key_press: executed!\n");
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
	// remove this part below after testing
	else if (keycode == KEY_UP)
	{
		t_pt temp;
		// temp = next_checkpoint(data->p1, data->dir_pt);
		temp = end_point(data, data->dir_pt);
		printf("key_press: endpoint (%f,%f)\n", temp.x, temp.y);
	}
	return (0);
}

int	key_release(int keycode, t_cub* data)
{
	// printf("key_release: executed!\n");
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
			keycode == KEY_W || 
			keycode == KEY_S ||
			keycode == KEY_A ||
			keycode == KEY_D)
		update_movement(data, keycode, 0);
	return (0);
}

int	render_cell(t_cub* data, int x, int y)
{
	char	*path = "./wall.xpm";
	int		img_width;
	int		img_height;
	t_vars	vars;

	img_width = 64;
	img_height = 64;
	vars = data->exec;

	void* img;
	// path = get_path(cell->value);
	// if (!path)
	// 	return (0);
	printf("before render_cell: %p\n", img);
	data->texture[0].img = mlx_xpm_file_to_image(data->exec.mlx, path, &img_width, &img_height);
	// data->texture[0].img = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
	printf("after render_cell: %p\n", img);
	mlx_put_image_to_window(vars.mlx, vars.win, data->texture[0].img, img_width * x, img_height * y);
	// mlx_put_image_to_window(vars.mlx, vars.win, data->texture[0].img, 640, 640);
	return (0);
}

int	render_map(t_cub *data)//char** map, t_vars vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		// printf("render_map:done\n");
		j = 0;
		while (data->map[i][j])
		{
			// printf("cell[%d][%d]\n", i, j);
			render_cell(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int cub_exec(t_cub* data)
{
	void* img;

	system("xset r off");
	printf("\e[32mcub_exec running.\n\e[0m");
 
	// mlx_key_hook(vars.win, key_press, data);
	mlx_hook(data->exec.win, 2, 1L<<0, key_press, data);
	mlx_hook(data->exec.win, 3, 1L<<1, key_release, data);
	mlx_hook(data->exec.win, 17, 0, mlx_close, &(data->exec));

	mlx_loop_hook(data->exec.mlx, update_state, data);

	mlx_loop(data->exec.mlx);

	mlx_destroy_display(data->exec.mlx);
	free(data->exec.mlx);
    return (0);
}
