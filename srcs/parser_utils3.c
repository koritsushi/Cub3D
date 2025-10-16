/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:18:38 by mliyuan           #+#    #+#             */
/*   Updated: 2025/10/13 17:18:38 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_flags(t_cub *data, int flags[])
{
	int	i;
	int	status;

	i = 0;
	status = 1;
	while (i < 6)
	{
		if (i < 4 && (flags[i] == 0 || flags[i] == 2))
		{
			status = 0;
			break ;
		}
		else if (i >= 4 && (flags[i] == -1 || flags[i] == 0 || flags[i] == 2))
		{
			status = 0;
			break ;
		}
		i++;
	}
	if (status == 0)
		return (0);
	return (1);
}

int	append_map(t_cub *data, char **content, int len)
{
	int	i;

	i = 0;
	data->height = append_height(content, len);
	data->width = append_width(content, len);
	if (data->height == 0 && data->width == 0)
		return (0);
	data->map = malloc(sizeof(char *) * (ft_arr_len(content + len) + 1));
	data->cmap = malloc(sizeof(char *) * (ft_arr_len(content + len) + 1));
	if (data->map == NULL || data->cmap == NULL)
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
