/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:21:04 by mliyuan           #+#    #+#             */
/*   Updated: 2025/10/13 17:18:30 by mliyuan          ###   ########.fr       */
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

int	ptypechecker_init(char *type[], int flags[])
// char	*read_file(int fd)
{
	type[0] = "NO";
	type[1] = "EA";
	type[2] = "SO";
	type[3] = "WE";
	type[4] = "F";
	type[5] = "C";
	type[6] = NULL;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	flags[5] = 0;
	return (1);
}

int	parse_tc(t_cub *data, char *content, int type)
{
	if (type < 4)
		return (parse_texture(data, content, type));
	else
		return (parse_color(data, content, type));
}

static int	parse_line(t_cub *data, char *line, char **type, int *flags)
{
	int	j;

	j = -1;
	ft_trimspaces(&line);
	while (type[++j] != NULL)
	{
		if (ft_strncmp(line, type[j], ft_strlen(type[j])) == 0)
		{
			if (flags[j] == 1)
				return (0);
			flags[j] += parse_tc(data, line, j);
			break ;
		}
	}
	return (1);
}

static int	validate_and_append(t_cub *data, char **content, int *flags, int j)
{
	if (check_flags(data, flags) == 0 || append_map(data, content, j) == 0)
		return (0);
	return (1);
}

int	parse_file(t_cub *data, char *file)
{
	int		i;
	int		flags[7];
	char	*type[7];
	char	**content;

	content = ft_split(file, '\n');
	ptypechecker_init(type, flags);
	if (ft_isempty(content))
		return (ft_free(data, 0), 0);
	i = -1;
	while (content[++i] && i < 6)
	{
		if (parse_line(data, content[i], type, flags) == 0)
			return (ft_free_parsing(content, data, flags));
	}
	if (validate_and_append(data, content, flags, i) == 0)
		return (ft_free_parsing(content, data, flags));
	return (ft_free_arr((void **)content), 1);
}

/*
int	parse_file(t_cub *data, char *file)
{
	int		i;
	int		j;
	int		flags[7];
	char	*type[7];
	char	**content;

	content = ft_split(file, '\n');
	ptypechecker_init(type, flags);
	if (ft_isempty(content) == 1)
		return (ft_free(data, 0), 0);
	i = -1;
	while (content[++i] != NULL && i < 6)
	{
		j = -1;
		while (type[++j] != NULL)
		{
			ft_trimspaces(&content[i]);
			if (ft_strncmp(content[i], type[j], ft_strlen(type[j])) == 0)
			{
				if (flags[j] == 1)
					return (ft_free_parsing(content, data, flags));
				flags[j] += parse_tc(data, content[i], j);
			}
		}
	}
	if (check_flags(data, flags) == 0 || append_map(data, content, j) == 0)
		return (ft_free_parsing(content, data, flags));
	return (ft_free_arr((void **)content), 1);
}
*/
