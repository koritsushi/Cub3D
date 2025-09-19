/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:38:05 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 16:38:05 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	create_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

int	valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	colors(t_cub *data, char *color)
{
	int				i;
	char			**rgbs;
	unsigned char	colors[3];
	int				valid;

	rgbs = ft_split_str(color + 1, " ,");
	i = ft_arr_len(rgbs);
	if (i != 3)
		return (-1);
	i = 0;
	while (i < 3)
	{
		if (valid_num(rgbs[i]) == 0)
			return (0);
		colors[i] = ft_atoi(rgbs[i]);
		if (colors[i] < 0 || colors[i] > 255)
			return (ft_free_arr((void **)rgbs), -1);
		i++;
	}
	ft_free_arr((void **)rgbs);
	valid = create_rgb(colors[0], colors[1], colors[2]);
	return (valid);
}

int	parse_color(t_cub *data, char *rgb, int type)
{
	int	status;

	status = colors(data, rgb);
	if (status == -1)
		return (0);
	if (type == 5)
		data->f_col = status;
	else
		data->c_col = status;
	return (1);
}
