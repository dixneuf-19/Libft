/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:54:44 by mzary             #+#    #+#             */
/*   Updated: 2024/10/27 13:04:10 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	proper(size_t len, size_t strlen)
{
	if (len < strlen)
		return (sizeof(char) * (len + 1));
	return (sizeof(char) * (strlen + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return ((char *)0);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (sub == (char *)0)
			return ((char *)0);
		ft_strlcpy(sub, "", 1);
	}
	else
	{
		sub = (char *)malloc(proper(len, ft_strlen(s) - start));
		if (sub == (char *)0)
			return ((char *)0);
		ft_strlcpy(sub, s + start, proper(len, ft_strlen(s) - start));
	}
	return (sub);
}
