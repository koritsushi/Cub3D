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

void	error_init(char *err[])
{
	err[0] = "./cube3D: Usage: ./.cub3d filename.cub\n";
	err[1] = "./cube3D: Invalid texture or color!";
	err[2] = "./cube3D: Invalid Map";
}

void	ft_error(int flag)
{
	char	*err[3];

	error_init(err);
	ft_putstr_fd("./cube3D: Error!\n", 2);
	ft_putstr_fd(err[flag], 2);
}

int	check_cub(int *fd, const char *file)
{
	int	i;

	i = ft_strlen(file);
	*fd = open(file, __O_DIRECTORY);
	if (ft_strncmp(file + (i - 4), ".cub", 4) == 0 && *fd == -1)
	{
		*fd = open(file, O_RDONLY);
		if (*fd == -1)
			return (0);
		return (1);
	}
	close(*fd);
	return (0);
}
