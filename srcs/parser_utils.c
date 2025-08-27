/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:38:57 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 16:38:57 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_ext(int *fd, const char *file, char *ext)
{
	int	i;

	i = ft_strlen(file);
	*fd = open(file, __O_DIRECTORY);
	if (ft_strncmp(file + (i - 4), ext, ft_strlen(ext)) == 0 && \
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
