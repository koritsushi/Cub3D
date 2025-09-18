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

void	dfs(t_cub *data, char **map, int x, int y)
{
	int		length;
	int		height;
	int		s;
	int		os;

	os = 0;
	s = 1;
	if (x < 0 || x >= data->width || y < 0 || y >= data->height ||\
map[x][y] != os)
		return ;
	map[x][y] = s;
	dfs(data, map, x + 1, y);
	dfs(data, map, x - 1, y);
	dfs(data, map, x, y + 1);
	dfs(data, map, x, y - 1); 
}

void	ft_flood_fill(t_cub *data, char **map, int x, int y)
{
	dfs(data, map, x, y);
}

int	parse_map(t_cub *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*p;
	int		status;

	i = 0;
	x = 0;
	y = 0;
	p = "NEWS";
	while (data->cmap[i] != NULL)
	{
		while (data->cmap[i][j] != '\0')
		{
			if (ft_strncmp(p, &data->cmap[i][j], 1) == 1)
			{
				status += 1;				
				y = i;
				x = j;
			}
			j++;
		}
		i++;
	}
	if (data->cmap[i] == NULL && status == 1)
	{
		ft_flood_fill(data, data->cmap, x, y);
		return (1);
	}
	return (0);
}
