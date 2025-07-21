/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:13:43 by mliyuan           #+#    #+#             */
/*   Updated: 2025/07/21 11:31:53 by booi             ###   ########.fr       */
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

//test
#endif
