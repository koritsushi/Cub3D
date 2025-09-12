/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:13:43 by mliyuan           #+#    #+#             */
/*   Updated: 2025/09/12 17:00:43 by mliyuan          ###   ########.fr       */
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

typedef struct s_texture
{
	void 	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}				t_var;

typedef struct	s_cub
{
	t_pt		p1;			// location of player1
	float		dir_angle;	// direction (0-360) that p1 is facing
	t_pt		dir_pt;		// use this for point translation

	t_var		exec;
	char		**map;
	int			height;
	int			width;
	t_texture	texture[4];
	int			f_col;
	int			c_col;
}				t_cub;



//utils.c
int		ft_isspace(char c);
int		ft_arr_len(char **ar);
//free.c
void	ft_free_arr(void **arr);
//error.c
void	ft_error(void);
//parser.c
int		parse_file(t_cub *data, char *file);
//parser_utils.c
int		append_height(char **content, int len);
int		append_width(char **content, int len);
int		check_ext(int *fd, const char *file, char *ext);
char	*read_file(int fd);
//parser_texture.c
int		parse_texture(t_cub *data, char *pathname, int type);
//parser_colors.c
int		colors(t_cub *data, char *color);
int		parse_color(t_cub *data, char *rgb, int type);
//parser_map.c
int		parse_map(t_cub *data);
//parser_utils2.c
char	**ft_split_str(char *str, char *set);

#endif
