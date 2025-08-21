/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:13:43 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/14 15:16:43 by mliyuan          ###   ########.fr       */
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

# define TURN_SPEED 1
# define MOVE_SPEED 1
# define PRECISION 0.001

typedef struct	s_point
{
	float	x;
	float	y;
}			t_pt;

typedef struct	s_vars
{
	void*	mlx;
	void*	win;

}				t_vars;

typedef struct	s_cub
{
	t_pt	p1;			// location of player1
	float	dir_angle;	// direction (0-360) that p1 is facing. east is 0, numbers increase anti-clockwise (follow trig)
	t_pt	dir_pt;		// use this for point translation
	// t_vars*	vars;

	int		move_fwd;
	int		move_back;
	int		move_left;
	int		move_right;
	int		turn_left;
	int		turn_right;

	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	int		*f_col;
	int		*c_col;
}			t_cub;

void	ft_error(void);
int		check_cub(int *fd, const char *file);

char	*read_file(int fd);

//exec
int		mlx_close(int keycode, t_vars *vars);
void	update_movement(t_cub* data, int keycode, int state);
int		key_press(int keycode, t_cub* data);
int		key_release(int keycode, t_cub* data);
int 	cub_exec(t_cub* data);

//update_state
void    player_turn(t_cub* data);
void	player_move(t_cub* data, char dir);
int	    update_state(t_cub* data);

//dda
float	d_to_border(float pt, float dir);
int		is_wholenum(float n);
int		orthogonal_solid(t_cub* data, t_pt pt);
int		diagonal_solid(t_cub* data, t_pt pt);
int		pt_on_solid(t_cub* data, t_pt pt);
float	dst_xy(float p, float vector);
t_pt	next_checkpoint(t_pt src, t_pt vector);
int		is_solid(t_cub* data, t_pt pt);
t_pt	end_point(t_cub* data);

//utils
t_pt    vector_of(float angle);
#endif
