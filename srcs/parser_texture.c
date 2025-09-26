/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:41:04 by mliyuan           #+#    #+#             */
/*   Updated: 2025/09/26 12:32:07 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	parse_texture(t_cub *data, char *pathname, int type)
{
	char	**content;
	int		width;
	int		height;
	int		fd;

	if (check_ext(&fd, pathname, ".xpm") == 0)
		return (0);
	close(fd);
	content = ft_split(pathname, ' ');
	if (content == NULL || content[1] == NULL)
		return (0);
	data->texture[type].img = mlx_xpm_file_to_image\
(data->exec.mlx, content[1], &width, &height);
	if (data->texture[type].img == NULL)
		return (ft_free_arr((void **) content), 1);
	data->texture[type].address = mlx_get_data_addr\
(data->texture[type].img, &data->texture[type].bpp, \
&data->texture[type].line_length, &data->texture[type].endian);
	ft_free_arr((void **) content);
	return (1);
}
