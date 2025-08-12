/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:13:43 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/12 11:05:52 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# if __linux__
#  include "../minilibx-linux/mlx.h"
#  include "../minilibx-linux/mlx_int.h"
#  define ESC			65307
#  define KEY_UP		65362
#  define KEY_DOWN		65364
#  define KEY_LEFT		65361
#  define KEY_RIGHT		65363
#  define KEY_W			119
#  define KEY_A			97
#  define KEY_S			115
#  define KEY_D			100
# endif
# define ON_DESTROY	17
# include <sys/time.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_point
{
	float	x;
	float	y;
}			t_pt;

typedef struct	s_cub
{
	t_pt	p1;			// location of player1
	float	dir_angle;	// direction (0-360) that p1 is facing
	t_pt	dir_pt;		// use this for point translation

	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		*f_col;
	int		*c_col;
}			t_cub;

void	error(void);

#endif
