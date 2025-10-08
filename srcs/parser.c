/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:21:04 by mliyuan           #+#    #+#             */
/*   Updated: 2025/10/08 14:46:55 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
The map must be closed/surrounded by walls, if not the program must return
an error.

Except for the map content, each type of element can be separated by one or
more empty lines.

Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

Except for the map, each type of information from an element can be separated
by one or more spaces.

The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.
*/

void	typechecker_init(char *type[], int flags[])
// char	*read_file(int fd)
{
	type[0] = "NO";
	type[1] = "SO";
	type[2] = "WE";
	type[3] = "EA";
	type[4] = "F";
	type[5] = "C";
	type[6] = NULL;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	flags[5] = 0;
}

int	check_flags(int flags[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i < 4 && flags[i] != 1)
			return (0);
		else if (flags[i] == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	parse_tc(t_cub *data, char *content, int type)
{
	if (type < 4)
		return (parse_texture(data, content, type));
	else
		return (parse_color(data, content, type));
}

int	append_map(t_cub *data, char **content, int len)
{
	int	i;

	i = 0;
	data->height = append_height(content, len);
	data->width = append_width(content, len);
	data->map = malloc(sizeof(char *) * (ft_arr_len(content + len) + 1));
	data->cmap = malloc(sizeof(char *) * (ft_arr_len(content + len) + 1));
	if (data->map == NULL)
		return (0);
	while (content[len] != NULL)
	{
		data->map[i] = ft_cstrdup(data, content[len]);
		data->cmap[i] = ft_cstrdup(data, content[len]);
		len++;
		i++;
	}
	data->map[i] = NULL;
	data->cmap[i] = NULL;
	return (1);
}

int	parse_file(t_cub *data, char *file)
{
	int		i;
	int		j;
	int		flags[7];
	char	*type[7];
	char	**content;

	typechecker_init(type, flags);
	content = ft_split(file, '\n');
	if (ft_isempty(content) == 0)
		return (0);
	i = -1;
	while (content[++i] != NULL && i < 6)
	{
		j = -1;
		while (type[++j] != NULL)
		{
			if (ft_strncmp(content[i], type[j], ft_strlen(type[j])) == 0)
				flags[j] += parse_tc(data, content[i], j);
		}
	}
	if (append_map(data, content, j) == 0)
		return (ft_free_arr((void **)content), 0);
	return (ft_free_arr((void **)content), check_flags(flags));
}
