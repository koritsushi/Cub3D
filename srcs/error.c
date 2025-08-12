/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:31:37 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/11 19:31:37 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_error(void)
{
	ft_putstr_fd("./cub3D: Error!\n", 2);
	ft_putstr_fd("./cub3D: usage: ./cub3d filename.cub\n", 2);
	exit(1);
}

int		check_cub(int *fd, const char *file)
{
	int	i;

	i = ft_strlen(file);
	if (ft_strncmp(file + (i - 4), ".cub", 4) == 0 &&\
open(file, __O_DIRECTORY) == -1)
	{
		*fd = open(file, O_RDONLY);
		if (*fd == -1)
		{
			close(*fd);
			return (0);
		}
		return (1);
	}
	return (0);
}