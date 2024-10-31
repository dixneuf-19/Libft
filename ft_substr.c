/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:54:44 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 16:43:20 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	proper(size_t len, size_t strlen)
{
	if (len < strlen)
		return (len + 1);
	return (strlen + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, "", 1);
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * proper(len, ft_strlen(s) - start));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, s + start, proper(len, ft_strlen(s) - start));
	}
	return (sub);
}
