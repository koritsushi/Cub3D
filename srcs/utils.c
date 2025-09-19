/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:36:28 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/21 16:36:28 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 7 && c <= 13))
		return (1);
	return (0);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}

char	**ft_arr_cpy(char **src)
{
	int			i;
	int			j;
	char		**dst;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char *) * (ft_arr_len(src)));
	if (dst == NULL || src == NULL)
		return (NULL);
	while (src[i] != NULL)
		dst[j++] = ft_strdup(src[i++]);
	dst[j] = NULL;
	return (dst);
}
