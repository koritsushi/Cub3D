/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:23:02 by mliyuan           #+#    #+#             */
/*   Updated: 2025/09/12 15:42:44 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
need to find player position char in any of the map
such as N, E, W, S
doesn't if there are multiple close map 
if there is no player char
no duplicate
*/

char	*ft_cstrdup(t_cub *data, const char *s)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) + data->width + 1);
	if (cpy == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\t')
			return (NULL);
		if (ft_isspace(s[i]) == 1)
			cpy[i] = '0';
		else
			cpy[i] = s[i];
		i++;
	}
	while (i < data->width)
		cpy[i++] = '0';
	cpy[i] = '\0';
	return (cpy);
}

int	dfs(t_cub *data, char **map, int x, int y)
{
	int	status;

	status = 0;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height || \
map[y][x] == ' ')
		return (1);
	else if (map[y][x] != '0')
		return (0);
	map[y][x] = '1';
	status += dfs(data, map, x, y + 1);
	status += dfs(data, map, x, y - 1);
	status += dfs(data, map, x + 1, y);
	status += dfs(data, map, x - 1, y);
	return (status);
}

int	ft_flood_fill(t_cub *data, char **map, int x, int y)
{
	return (dfs(data, map, x, y));
}

int	parse_map(t_cub *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*p;
	int		status;

	i = -1;
	x = 0;
	y = 0;
	status = 0;
	p = "NEWS";
	while (data->cmap[++i] != NULL)
	{
		j = -1;
		while (data->cmap[i][++j] != '\0')
		{
			if (ft_strncmp(p, data->cmap[i] + j, 1) == 0)
			{
				status += 1;
				y = i;
				x = j;
			}
		}
	}
	if (status == 1)
	{
		data->cmap[y][x] = '0';
		if (ft_flood_fill(data, data->cmap, x, y) > 0)
			return (ft_free_arr((void **)data->cmap), 0);
		return (1);
	}
	return (0);
}
