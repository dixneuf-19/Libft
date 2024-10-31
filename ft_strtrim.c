/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:05:23 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 16:38:35 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	fromset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

static int	lower_trim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(s1) && fromset(*(s1 + i), set))
	{
		i++;
	}
	return (i);
}

static int	upper_trim(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen(s1) - 1;
	while (0 <= j && fromset(*(s1 + j), set))
	{
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*copy;
	int		i;
	int		j;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	i = lower_trim(s1, set);
	j = upper_trim(s1, set);
	if (j < i)
		size = 1;
	else
		size = j - i + 2;
	copy = (char *)malloc(sizeof(char) * size);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1 + i, size);
	return (copy);
}
