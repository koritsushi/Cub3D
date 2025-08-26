/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:21:04 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 16:38:46 by mliyuan          ###   ########.fr       */
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
		if (flags[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int		check_ext(int *fd, const char *file, char *ext)
{
	int	i;

	i = ft_strlen(file);
	*fd = open(file, __O_DIRECTORY);
	if (ft_strncmp(file + (i - 4), ext, ft_strlen(ext)) == 0 &&\
 *fd == -1)
	{
		*fd = open(file, O_RDONLY);
		if (*fd == -1)
			return (0);
		return (1);
	}
	close(*fd);
	return (0);
}

char	*read_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*final;

	final = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin(final, line);
		free(final);
		final = ft_strdup(tmp);
		free(line);
		free(tmp);
	}
	close(fd);
	return (final);
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
	if (content == NULL)
		return (0);
	i = 0;
	while (content[i] != NULL && i < 6)
	{
		j = 0;
		while (type[j] != NULL)
		{
			if (ft_strncmp(content[i], type[j], ft_strlen(type[j])) == 0)
			{
				if (j < 4)
					parse_texture(data, content[i], j);
				else
					parse_color(data, content[i], j);
				flags[j] += 1;
			}
			j++;
		}
		i++;
	}
	return (check_flags(flags));
}