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
	ft_putstr_fd("./cub3d: Error!\n", 2);
	ft_putstr_fd("./cub3d: usage: ./cub3d filename.cub\n", 2);
	exit(1);
}