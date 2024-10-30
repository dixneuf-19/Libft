/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:10 by mzary             #+#    #+#             */
/*   Updated: 2024/10/29 17:19:37 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	bytes;

	bytes = nmemb * size;
	if (nmemb && bytes / nmemb != size)
		return ((void *)0);
	pointer = malloc(sizeof(char) * (nmemb * size));
	if (pointer == (void *)0)
		return ((void *)0);
	ft_memset(pointer, 0, nmemb * size);
	return (pointer);
}
