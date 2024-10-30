/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:44:05 by mzary             #+#    #+#             */
/*   Updated: 2024/10/23 13:59:05 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
	{
		return ((char *)(s + ft_strlen(s)));
	}
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (0);
}
