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
# define MOVE_SPEED 0.3
# define PRECISION 	0.001
# define FOV 		120
# define S_WIDTH	640
# define S_HEIGHT	480
# define HORIZON	11
# define CLOSEUP	1

# define NORTHWEST  5
# define NORTH 		1
# define NORTHEAST 	6
# define WEST 		2
# define HERE 		9
# define EAST 		3
# define SOUTHWEST 	7
# define SOUTH 		4
# define SOUTHEAST 	8

typedef struct s_image
{
	void 	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_image;

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

	t_vars	vars;
	char	**map;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	
	int		*f_col;
	int		*c_col;
	t_image	snapshot;
	t_image	texture[4];
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

//exec_endpoint
int		check_spt(char** map, t_pt pt, t_pt vector, int side);
int		check_ocpt(char** map, int x, int y, t_pt vector);
int		check_dcpt(char** map, int x, int y, t_pt vector);
int		is_stop(char** map, t_pt pt, t_pt vector);
t_pt	end_point(t_cub* data, t_pt vector);

//dda
float	next_xy(float p, float vector);
t_pt	next_checkpoint(t_pt src, t_pt vector);

//utils
t_pt    vector_of(float angle);
int	    is_wholenum(float n);
int     is_zero(float n);
int		is_solid(char cell);
int     is_bordering(t_pt pt);
int     direction_of(t_pt vector);
t_pt    snap_xy(t_pt pt);
float   d_fisheye(t_pt pt1, t_pt pt2, float angle);
float   d_betw(t_pt pt1, t_pt pt2);
float   mod_angle(float angle, float mod);

//cell checks
char    cell_beside_ipt(char** map, t_pt pt, int dir);
char    cell_beside_wpt(char** map, t_pt pt, int dir);
char    cell_beside_bpt(char** map, t_pt pt, int dir);
char    cell_beside(char** map, t_pt pt, int dir);

//dummy
int    print_arr(char **arr);
char**  create_dummy();


t_pt	movement1(t_pt src, t_pt vector, char** map);
t_pt	movement2(t_pt src, t_pt vector, char** map);
t_pt	dst_of2(t_pt src, t_pt vector, char** map);

int render_map(t_cub* data);
int	render_cell(t_cub* data, int x, int y, void* img);
int	render_col(t_cub* data);
int render_screen(t_cub* data);
int create_colourcode(int t, int r, int g, int b);
void colour_col(t_cub* data, int col);
void render_snapshot(t_cub* data);
#endif
