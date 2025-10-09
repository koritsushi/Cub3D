/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_updatestate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:47:40 by booi              #+#    #+#             */
/*   Updated: 2025/10/09 15:32:42 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

void	player_turn(t_cub *data);
void	player_move(t_cub *data, char dir);
int		update_state(t_cub *data);

t_pt	dst_of(t_cub *data, t_pt vector)
{
	t_pt	dst;
	t_pt	move;
	t_pt	endpt;

	dst.x = data->p1.x + (vector.x * MOVE_SPEED);
	dst.y = data->p1.y + (vector.y * MOVE_SPEED);
	move.x = vector.x;
	move.y = 0;
	endpt = end_point(data, data->p1, move);
	if (move.x > 0 && endpt.x <= dst.x + BUFFER)
		dst.x = endpt.x - BUFFER;
	else if (move.x < 0 && endpt.x >= dst.x - BUFFER)
		dst.x = endpt.x + BUFFER;
	move.x = 0;
	move.y = vector.y;
	endpt = end_point(data, data->p1, move);
	if (move.y > 0 && endpt.y <= dst.y + BUFFER)
		dst.y = endpt.y - BUFFER;
	else if (move.y < 0 && endpt.y >= dst.y - BUFFER)
		dst.y = endpt.y + BUFFER;
	return (dst);
}

void	player_turn(t_cub *data)
{
	if (data->tleft)
		data->dir_angle = mod_angle((data->dir_angle + TURN_SPEED), 360);
	else if (data->tright)
		data->dir_angle = mod_angle((data->dir_angle - TURN_SPEED), 360);
	data->dir_pt = vector_of(data->dir_angle);
	update_cameraplane(data);
}

void	player_move(t_cub *data, char dir)
{
	float	angle;

	angle = data->dir_angle;
	if (dir == 'w')
		;
	else if (dir == 'q')
		angle = mod_angle(data->dir_angle + 45, 360);
	else if (dir == 'a')
		angle = mod_angle(data->dir_angle + 90, 360);
	else if (dir == 'z')
		angle = mod_angle(data->dir_angle + 135, 360);
	else if (dir == 'x')
		angle = mod_angle(data->dir_angle + 180, 360);
	else if (dir == 'c')
		angle = mod_angle(data->dir_angle - 135, 360);
	else if (dir == 'd')
		angle = mod_angle(data->dir_angle - 90, 360);
	else if (dir == 'e')
		angle = mod_angle(data->dir_angle - 45, 360);
	data->p1 = dst_of(data, vector_of(angle));
}

// this is the main function for auto-refreshing state and rendering view.
int	update_state(t_cub *data)
{
	if (!(data->tleft && data->tright) && (data->tleft || data->tright))
		player_turn(data);
	if (data->mfwd && !data->mback && data->mleft && !data->mright)
		player_move(data, 'q');
	else if (data->mfwd && !data->mback && !data->mleft && !data->mright)
		player_move(data, 'w');
	else if (data->mfwd && !data->mback && !data->mleft && data->mright)
		player_move(data, 'e');
	else if (!data->mfwd && !data->mback && data->mleft && !data->mright)
		player_move(data, 'a');
	else if (!data->mfwd && !data->mback && !data->mleft && data->mright)
		player_move(data, 'd');
	else if (!data->mfwd && data->mback && data->mleft && !data->mright)
		player_move(data, 'z');
	else if (!data->mfwd && data->mback && !data->mleft && !data->mright)
		player_move(data, 'x');
	else if (!data->mfwd && data->mback && !data->mleft && data->mright)
		player_move(data, 'c');
	render_snapshot(data);
	return (0);
}
