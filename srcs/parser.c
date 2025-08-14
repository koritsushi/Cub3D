/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:21:04 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/14 15:18:19 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// int	parse_texture()
// {

// }

// int	parse_color()
// {

// }

// int	parse_map()
// {
	
// }

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