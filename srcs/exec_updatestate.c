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

// src in inside cell, or on border but verified passable
t_pt	movement1(t_pt src, t_pt vector, char** map)
{
	t_pt	check;
	t_pt	dst;

	check = next_checkpoint(src, vector);
	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);

	if (d_betw(src, check) >= d_betw(src, dst))
		return (dst);
	else
	{
		vector.x = dst.x - check.x;  
		vector.y = dst.y - check.y;  
		return (dst_of2(check, vector, map));
	}
}

// src is on a cell border
t_pt	movement2(t_pt src, t_pt vector, char** map)
{
	if (!is_stop(map, src, vector))
		return movement1(src, vector, map);
	else if (is_bordering(src) == 1) //vside
	{
		vector.x = 0;
		return movement1(src, vector, map);
		//need to add the x vector back in the next cycle
	}
	else if (is_bordering(src) == 2) //hside
	{
		vector.y = 0;
		return movement1(src, vector, map);
		//need to add the y vector back in the next cycle
	}
	else if (is_bordering(src) == 3) //corner
		return (src);
	else
		return (src);
}

t_pt	dst_of2(t_pt src, t_pt vector, char** map)
{
	t_pt	check;
	t_pt	dst;
	t_pt	temp;

	check = next_checkpoint(src, vector);
	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);
	temp.x = 0;
	temp.y = 0;
	printf("dst_of: check (%f,%f)\n", check.x, check.y);
	printf("dst_of: d_betw(%f), d_betw(%f)\n", d_betw(src, check), d_betw(src, dst));
	if (is_bordering(src))
	{ // 2
		if (!is_stop(map, src, vector))
			return movement1(src, vector, map);
		else if (is_bordering(src) == 1) //vside
		{
			vector.x = 0;
			return movement1(src, vector, map);
			//need to add the x vector back in the next cycle
		}
		else if (is_bordering(src) == 2) //hside
		{
			vector.y = 0;
			return movement1(src, vector, map);
			//need to add the y vector back in the next cycle
		}
		else if (is_bordering(src) == 3) //corner
			return (src);
		else
			return (src);
	}
	else
		return movement1(src, vector, map);
}

t_pt	dst_of(t_pt src, t_pt vector, char** map)
{
	t_pt	dst;
	t_pt	check;
	t_pt	temp;

	dst.x = src.x + (vector.x * MOVE_SPEED);
	dst.y = src.y + (vector.y * MOVE_SPEED);
	check = next_checkpoint(src, vector);
	temp.x = 0;
	temp.y = 0;
	printf("dst_of: check (%f,%f)\n", check.x, check.y);
	printf("dst_of: d_betw(%f), d_betw(%f)\n", d_betw(src, check), d_betw(src, dst));
	if (is_bordering(src) && is_stop(map, src, vector))
	{
		temp.x = dst.x - src.x;
		temp.y = 0; 
		if (is_stop(map, src, temp))
			dst.x = src.x;
		temp.y = dst.y - src.y;
		temp.x = 0; 
		if (is_stop(map, src, temp))
			dst.y = src.y;
		return (dst);
	}
	else if (d_betw(src, check) < d_betw(src, dst))
	{
		printf("dst_of: in loop\n");
		if (is_stop(map, check, vector))
		{
			temp.x = dst.x - check.x;
			temp.y = 0; 
			if (is_stop(map, check, temp))
				dst.x = check.x;
			temp.y = dst.y - check.y;
			temp.x = 0; 
			if (is_stop(map, check, temp))
				dst.y = check.y;
			return (dst);
		}
		else
			return (dst);
	}
	return (dst);
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
		data->p1 = dst_of2(data->p1, vector_of(data->dir_angle), data->map);
	else if (dir == 'b' && is_clear(data))
		data->p1 = dst_of2(data->p1, vector_of(mod_angle(data->dir_angle + 180, 360)), data->map);
	else if (dir == 'l' && is_clear(data))
		data->p1 = dst_of2(data->p1, vector_of(mod_angle(data->dir_angle + 90, 360)), data->map);
	else if (dir == 'r' && is_clear(data))
		data->p1 = dst_of2(data->p1, vector_of(mod_angle(data->dir_angle - 90, 360)), data->map);
	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
}

// void	player_move(t_cub* data, char dir)
// {
// 	if (dir == 'f' && is_clear(data))
// 	{
// 		data->p1.x += (data->dir_pt.x * MOVE_SPEED);
// 		data->p1.y += (data->dir_pt.y * MOVE_SPEED);
// 	}
// 	else if (dir == 'b' && is_clear(data))
// 	{
// 		data->p1.x -= (data->dir_pt.x * MOVE_SPEED);
// 		data->p1.y -= (data->dir_pt.y * MOVE_SPEED);
// 	}
// 	else if (dir == 'l' && is_clear(data))
// 	{
// 		data->p1.x += (data->dir_pt.y * MOVE_SPEED);
// 		data->p1.y -= (data->dir_pt.x * MOVE_SPEED);
// 	}
// 	else if (dir == 'r' && is_clear(data))
// 	{
// 		data->p1.x -= (data->dir_pt.y * MOVE_SPEED);
// 		data->p1.y += (data->dir_pt.x * MOVE_SPEED);
// 	}
// 	printf("player_move: p1 (%f, %f)\n", data->p1.x, data->p1.y);
// }

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
