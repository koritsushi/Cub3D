/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:23:02 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 15:23:02 by mliyuan          ###   ########.fr       */
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
int	bfs()
{

}

int	flood_fill(char **map, int x, int y)
{
	int		length;
	int		height;
	char	**copy;

	copy = map;
	height = y;
	length = x;

	return (1);
}

int	parse_map(t_cub *data, char *file)
{
	
}