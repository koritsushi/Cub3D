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

int	dfs(t_cub *data, char **map, int x, int y)
{
	int	status;

	status = 0;
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
		return (1);
	else if (map[x][y] == '1')
		return (0);
	else if (map[x][y] != '0')
		return (1);
	map[x][y] = '1';
	status += dfs(data, map, x + 1, y);
	status += dfs(data, map, x - 1, y);
	status += dfs(data, map, x, y + 1);
	status += dfs(data, map, x, y - 1);
	return (status);
}

int	ft_flood_fill(t_cub *data, char **map, int x, int y)
{
	return (dfs(data, map, x, y));
}

int	check_pm(t_cub *data, int status, int x, int y)
{
	if (status == 1)
	{
		data->cmap[x][y] = '0';
		if (ft_flood_fill(data, data->cmap, x, y) > 0)
			return (0);
		init_p1(data, y, x, data->map[x][y]);
		update_cameraplane(data);
		printf("./cube3D: Valid Map\n");
		return (1);
	}
	return (0);
}

int	check_ppos(char player_pos, int c[2], int x, int y)
{
	int		i;
	char	*checker;

	i = 0;
	checker = "NEWS";
	while (checker[i] != '\0')
	{
		if (player_pos == checker[i])
		{
			c[0] = x;
			c[1] = y;
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_map(t_cub *data)
{
	int				i;
	int				j;
	int				k;
	int				c[2];
	int				status;

	i = -1;
	status = 0;
	while (data->cmap[++i] != NULL)
	{
		j = -1;
		while (data->cmap[i][++j] != '\0')
			status += check_ppos(data->cmap[i][j], c, i, j);
	}
	return (check_pm(data, status, c[0], c[1]));
}
