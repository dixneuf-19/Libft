/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:35:53 by mzary             #+#    #+#             */
/*   Updated: 2024/10/27 13:01:03 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (c == (char *)0)
		return ((char *)0);
	ft_strlcpy(c, s, ft_strlen(s) + 1);
	return (c);
}
