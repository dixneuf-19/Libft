/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:20:35 by mzary             #+#    #+#             */
/*   Updated: 2024/10/25 18:04:25 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	free_all(char **splits)
{
	while (*splits)
	{
		free(*splits);
		splits++;
	}
	free(splits);
}

int	ft_splits(char const *s, char c, char **splits, int count)
{
	int	i;
	int	st;
	int	split;

	i = 0;
	split = 0;
	while (split < count)
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		splits[split] = (char *)malloc(sizeof(char) * (i - st + 1));
		if (splits[split] == (char *)0)
		{
			free_all(splits);
			return (0);
		}
		ft_strlcpy(splits[split], s + st, i - st + 1);
		split++;
	}
	splits[count] = (char *)0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		count;

	if (!s)
		return ((char **)0);
	count = s_count(s, c);
	splits = (char **)malloc(sizeof(char *) * (count + 1));
	if (splits == (char **)0)
		return ((char **)0);
	if (!ft_splits(s, c, splits, count))
		return ((char **)0);
	return (splits);
}
