/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dummymap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: booi <booi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:11:57 by booi              #+#    #+#             */
/*   Updated: 2025/08/22 10:11:58 by booi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

int    print_arr(char **arr);
char**  create_dummy();

int    print_arr(char **arr)
{
	int i;
	int j;

	i = -1;

	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return (0);
}

char**  create_dummy()
{
	char** map;
	char* row0 = "1111111111";   
	char* row1 = "1000000001";   
	char* row2 = "1000000001";   
	char* row3 = "1000000001";   
	char* row4 = "1000000001";   
	char* row5 = "1000000001";   
	char* row6 = "1000000001";   
	char* row7 = "1000000001";   
	char* row8 = "1000000001";   
	char* row9 = "1111111111";   


	map = malloc(11 * sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = row0;
	map[1] = row1;
	map[2] = row2;
	map[3] = row3;
	map[4] = row4;
	map[5] = row5;
	map[6] = row6;
	map[7] = row7;
	map[8] = row8;
	map[9] = row9;
	return (map);
}