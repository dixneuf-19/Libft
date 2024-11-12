/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:45:16 by mzary             #+#    #+#             */
/*   Updated: 2024/10/23 13:38:13 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!dst && !size)
		return (ft_strlen(src)); // thank you Imane
	len = ft_strlen((const char *)dst);
	if (size >= ft_strlen((const char *)dst) + 1)
	{
		ft_strlcpy(dst + ft_strlen(dst), src, size - ft_strlen(dst));
		return (len + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
