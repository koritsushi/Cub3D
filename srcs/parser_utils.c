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

int	parse_texture(t_cub *data, char *pathname, int type)
{
	return (0);
}

int	parse_color(t_cub *data, char *rgb, int type)
{
	int	status;

	status = 0;
	status = colors(data, rgb);
	if (status == -1)
		return (0);
	if (type == 5)
		data->f_col = status;
	else 
		data->c_col = status;
	return (1);
}