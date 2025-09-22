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

void    player_turn(t_cub* data);
void	player_move(t_cub* data, char dir);
int	    update_state(t_cub* data);

t_pt	dst_of3(t_cub* data, t_pt vector)
{
	t_pt	dst;
	t_pt	move;
	t_pt	endpt;
	
	dst.x = data->p1.x + (vector.x * MOVE_SPEED);
	dst.y = data->p1.y + (vector.y * MOVE_SPEED);
	move.x = vector.x;
	move.y = 0;
	endpt = end_point(data, data->p1, move);
	if (move.x > 0 && endpt.x <= dst.x)
	dst.x = endpt.x - (1.05 * PRECISION);
	else if (move.x < 0 && endpt.x >= dst.x)
	dst.x = endpt.x + (1.05 * PRECISION);
	
	move.x = 0;
	move.y = vector.y;
	printf("dst_of3 DEBUG, dst (%f, %f) vector(%f, %f), move (%f, %f)\n", dst.x, dst.y, vector.x, vector.y, move.x, move.y);
	// printf("dst_of3 DEBUG, x %f\n", dst.x);
	endpt = end_point(data, data->p1, move);
	if (move.y > 0 && endpt.y <= dst.y)
		dst.y = endpt.y - (1.05 * PRECISION);
	else if (move.y < 0 && endpt.y >= dst.y)
		dst.y = endpt.y + (1.05 * PRECISION);
	
	return (dst);
}

void	player_turn(t_cub* data)
{
	// printf("player_turn: running\n");
	if (data->turn_left)
		data->dir_angle = mod_angle((data->dir_angle + TURN_SPEED), 360);
	else if (data->turn_right)
		data->dir_angle = mod_angle((data->dir_angle - TURN_SPEED), 360);
	// {
	// 	data->dir_angle = (data->dir_angle - TURN_SPEED);
	// 	if (data->dir_angle < 0)
	// 		data->dir_angle = 360 + data->dir_angle;
	// }
	data->dir_pt = vector_of(data->dir_angle);
	update_cameraplane(data);
	// if (data->dir_angle == 0)
	// 	data->dir_pt.y = 0;
	printf("player_turn: angle %f ", data->dir_angle);
	printf("dir_pt is (%f, %f)\n", data->dir_pt.x, data->dir_pt.y);
}

void	player_move(t_cub* data, char dir)
{
	float angle;
	angle = data->dir_angle;
	printf("player_move begin\n");
	// printf("player_move: current p1 (%f, %f), endpoint (%f, %f)\n", data->p1.x, data->p1.y, end_point(data, data->dir_pt).x, end_point(data, data->dir_pt).y);
	printf("player_move: current p1 (%f, %f))\n", data->p1.x, data->p1.y);
	if (dir == 'w')
		// data->p1 = dst_of3(data, vector_of(data->dir_angle));
		;
	else if (dir == 'q')
		angle = mod_angle(data->dir_angle + 45, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 45, 360)));
	else if (dir == 'a')
		angle = mod_angle(data->dir_angle + 90, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 90, 360)));
	else if (dir == 'z')
		angle = mod_angle(data->dir_angle + 135, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 135, 360)));
	else if (dir == 'x')
		angle = mod_angle(data->dir_angle + 180, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 180, 360)));
	else if (dir == 'c')
		angle = mod_angle(data->dir_angle - 135, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle - 135, 360)));
	else if (dir == 'd')
		angle = mod_angle(data->dir_angle - 90, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle - 90, 360)));
	else if (dir == 'e')
		angle = mod_angle(data->dir_angle - 45, 360);
		// data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle - 45, 360)));
	printf("angle %f, vector (%f, %f)\n", angle, vector_of(angle).x, vector_of(angle).y);
	data->p1 = dst_of3(data, vector_of(angle));
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}


// this is the main function for auto-refreshing state and rendering view.
int	update_state(t_cub* data)
{
	// usleep(50000);
	// printf("update_state: running\n");
	if (!(data->turn_left && data->turn_right) && (data->turn_left || data->turn_right))
		player_turn(data);
	if (data->move_fwd && !data->move_back && data->move_left && !data->move_right)
		player_move(data, 'q');
	else if (data->move_fwd && !data->move_back && !data->move_left && !data->move_right)
		player_move(data, 'w');
	else if (data->move_fwd && !data->move_back && !data->move_left && data->move_right)
		player_move(data, 'e');
	else if (!data->move_fwd && !data->move_back && data->move_left && !data->move_right)
		player_move(data, 'a');
	else if (!data->move_fwd && !data->move_back && !data->move_left && data->move_right)
		player_move(data, 'd');
	else if (!data->move_fwd && data->move_back && data->move_left && !data->move_right)
		player_move(data, 'z');
	else if (!data->move_fwd && data->move_back && !data->move_left && !data->move_right)
		player_move(data, 'x');
	else if (!data->move_fwd && data->move_back && !data->move_left && data->move_right)
		player_move(data, 'c');
	render_snapshot(data);
	return (0);
}

// void	player_move(t_cub* data, char dir)
// {
// 	printf("player_move: current p1 (%f, %f)\n", data->p1.x, data->p1.y);
// 	if (dir == 'f')
// 		data->p1 = dst_of3(data, vector_of(data->dir_angle));
// 	else if (dir == 'b')
// 		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 180, 360)));
// 	else if (dir == 'l')
// 		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle + 90, 360)));
// 	else if (dir == 'r')
// 		data->p1 = dst_of3(data, vector_of(mod_angle(data->dir_angle - 90, 360)));
// 	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
// }

// int	update_state(t_cub* data)
// {
// 	usleep(100000);
// 	// printf("update_state: running\n");
// 	if (!(data->turn_left && data->turn_right) && (data->turn_left || data->turn_right))
// 		player_turn(data);
// 	if (data->move_fwd && !data->move_back)
// 		player_move(data, 'f');
// 	if (data->move_back && !data->move_fwd)
// 		player_move(data, 'b');
// 	if (data->move_left && !data->move_right)
// 		player_move(data, 'l');
// 	if (data->move_right && !data->move_left)
// 		player_move(data, 'r');
// 	// render_snapshot(data);
// 	return (0);
// }