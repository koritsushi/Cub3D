/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliyuan <mliyuan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:39:10 by mliyuan           #+#    #+#             */
/*   Updated: 2025/08/19 17:39:10 by mliyuan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_delimiter(char c, char *delimiter)
{
	int	i;

	i = 0;
	while (delimiter[i] != '\0')
	{
		if (c == delimiter[i])
			return (1);
		i++;
	}
	return (0);
}

/*
count_ words for split_str
	while (s[++i] is not null)
		while (delimiter[i] is not null)
			if (ft_delimiter(s[i]) == 1)
				s[i] = ' '
			else if (ft_delimiter(s[i + 1]) == 0 && s[i + 1] == '\0')
			{
				count++;	
				break ;
			}
			count++;
	}
*/
int	ft_count_words(char *s, char *delimiter)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		while (ft_delimiter(s[i], delimiter) == 1)
		{
			if (ft_delimiter(s[i + 1], delimiter) == 0)
			{
				count++;
				break ;
			}
			i++;
		}
	}
	return (count);
}

void	ft_strword(char **dst, char const *src, char *delimiter)
{
	char		**tab_sp;
	char const	*tmp;

	tmp = src;
	tab_sp = dst;
	while (*tmp != '\0')
	{
		while (ft_delimiter(*src, delimiter))
			src++;
		tmp = src;
		while (*tmp && ft_delimiter(*tmp, delimiter) == 0)
			tmp++;
		if (ft_delimiter(*tmp, delimiter) || tmp > src)
		{
			*tab_sp = ft_substr(src, 0, tmp - src);
			src = tmp;
			tab_sp++;
		}
	}
	*tab_sp = NULL;
}

char	**ft_split_str(char *s, char *delimiter)
{
	char	**cpy;
	int		count;

	if (s == NULL || delimiter == NULL)
		return (NULL);
	count = ft_count_words(s, delimiter);
	if (count == 0)
		return (NULL);
	cpy = malloc(sizeof(cpy) * (count + 1));
	ft_strword(cpy, s, delimiter);
	return (cpy);
}
