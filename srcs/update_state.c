/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:47:40 by booi              #+#    #+#             */
/*   Updated: 2025/08/19 21:47:43 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

void	adjust_dir_pt(t_cub* data);
void    player_turn(t_cub* data);
void	player_move(t_cub* data, char dir);
int	    update_state(t_cub* data);

void	adjust_dir_pt(t_cub* data)
{
	data->dir_pt.x = sin((float)data->dir_angle / 180 * M_PI) * MOVE_SPEED;
	data->dir_pt.y = cos((float)data->dir_angle / 180 * M_PI) * MOVE_SPEED;
	printf("adjust_dir_pt: (%f, %f)\n", data->dir_pt.x, data->dir_pt.y);
}

void	player_turn(t_cub* data)
{
	printf("player_turn: running\n");
	if (data->turn_left)
		data->dir_angle = (data->dir_angle + TURN_SPEED) % 360;
	else if (data->turn_right)
	{
		data->dir_angle = (data->dir_angle - TURN_SPEED);
		if (data->dir_angle < 0)
			data->dir_angle = 360 + data->dir_angle;
	}
	printf("player_turn: angle is now %d\n", data->dir_angle);
	adjust_dir_pt(data);
}

void	player_move(t_cub* data, char dir)
{
	if (dir == 'f')
	{
		data->p1.x += (data->dir_pt.x * MOVE_SPEED);
		data->p1.y += (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'b')
	{
		data->p1.x -= (data->dir_pt.x * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'l')
	{
		data->p1.x -= (data->dir_pt.y * MOVE_SPEED);
		data->p1.y += (data->dir_pt.x * MOVE_SPEED);
	}
	else if (dir == 'r')
	{
		data->p1.x += (data->dir_pt.y * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.x * MOVE_SPEED);
	}
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}
// this is the main function for auto-refreshing state and rendering view.
int	update_state(t_cub* data)
{
	usleep(500000);
	printf("update_state: running\n");
	if (!(data->turn_left && data->turn_right) && (data->turn_left || data->turn_right))
		player_turn(data);
	if (data->move_fwd && !data->move_back)
		player_move(data, 'f');
	if (data->move_back && !data->move_fwd)
		player_move(data, 'b');
	if (data->move_left && !data->move_right)
		player_move(data, 'l');
	if (data->move_right && !data->move_left)
		player_move(data, 'r');
	return (0);
}