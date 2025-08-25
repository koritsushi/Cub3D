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

int		is_clear(t_cub* data);
void    player_turn(t_cub* data);
void	player_move(t_cub* data, char dir);
int	    update_state(t_cub* data);

int		is_clear(t_cub* data)
{
	return (1);
}

void	player_turn(t_cub* data)
{
	// printf("player_turn: running\n");
	if (data->turn_left)
		data->dir_angle = fmod((data->dir_angle + TURN_SPEED), 360);
	else if (data->turn_right)
	{
		data->dir_angle = (data->dir_angle - TURN_SPEED);
		if (data->dir_angle < 0)
			data->dir_angle = 360 + data->dir_angle;
	}
	data->dir_pt = vector_of(data->dir_angle);
	printf("player_turn: angle %f ", data->dir_angle);
	printf("dir_pt is (%f, %f)\n", data->dir_pt.x, data->dir_pt.y);
}

void	player_move(t_cub* data, char dir)
{
	if (dir == 'f' && is_clear(data))
	{
		data->p1.x += (data->dir_pt.x * MOVE_SPEED);
		data->p1.y += (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'b' && is_clear(data))
	{
		data->p1.x -= (data->dir_pt.x * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.y * MOVE_SPEED);
	}
	else if (dir == 'l' && is_clear(data))
	{
		data->p1.x += (data->dir_pt.y * MOVE_SPEED);
		data->p1.y -= (data->dir_pt.x * MOVE_SPEED);
	}
	else if (dir == 'r' && is_clear(data))
	{
		data->p1.x -= (data->dir_pt.y * MOVE_SPEED);
		data->p1.y += (data->dir_pt.x * MOVE_SPEED);
	}
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}

// this is the main function for auto-refreshing state and rendering view.
int	update_state(t_cub* data)
{
	usleep(100000);
	// printf("update_state: running\n");
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