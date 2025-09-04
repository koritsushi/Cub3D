/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:23:13 by booi              #+#    #+#             */
/*   Updated: 2025/09/02 10:23:14 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>


int create_colourcode(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

//processing texture
int	side_to_use(t_pt endpt, t_pt vector)
{
	if (is_bordering(endpt) == 1 && vector.x > 0)
		return (WEST);
	else if (is_bordering(endpt) == 1 && vector.x < 0)
		return (EAST);
	else if (is_bordering(endpt) == 2 && vector.y > 0)
		return (NORTH);
	else if (is_bordering(endpt) == 2 && vector.y < 0)
		return (SOUTH);
	else if (is_bordering(endpt) == 3)
		return (NORTH); // this is arbitrary. need to fix later
	else
		return (-1);
}

float use_texture_col(t_pt pt)
{
	if (is_wholenum(pt.x))
		return (fmodf(pt.y, 1.000));
	else
		return (fmodf(pt.x, 1.000));
}

//processing texture