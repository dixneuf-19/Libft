/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:20:35 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 16:26:04 by mzary            ###   ########.fr       */
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
		if (splits[split] == NULL)
		{
			free_all(splits);
			return (0);
		}
		ft_strlcpy(splits[split], s + st, i - st + 1);
		split++;
	}
	splits[count] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	int		count;

	if (!s)
		return (NULL);
	count = s_count(s, c);
	splits = (char **)malloc(sizeof(char *) * (count + 1));
	if (splits == NULL)
		return (NULL);
	if (!ft_splits(s, c, splits, count))
		return (NULL);
	return (splits);
}
