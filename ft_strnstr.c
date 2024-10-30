/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:47:25 by mzary             #+#    #+#             */
/*   Updated: 2024/10/27 12:50:38 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	pos;
	size_t	l_len;

	l_len = ft_strlen(little);
	if (*(little) == '\0')
		return ((char *)(big));
	pos = 0;
	while (*(big + pos) && pos < len)
	{
		if (!ft_strncmp(big + pos, little, l_len) && pos + l_len - 1 <= len - 1)
			return ((char *)(big + pos));
		pos++;
	}
	return ((char *)0);
}
