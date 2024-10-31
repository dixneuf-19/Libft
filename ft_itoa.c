/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:26:40 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 15:25:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*edge_case(int n)
{
	char	*edge_result;

	if (n == 0)
	{
		edge_result = (char *)malloc(sizeof(char) * 2);
		if (edge_result == NULL)
			return (NULL);
		ft_strlcpy(edge_result, "0", 2);
	}
	else
	{
		edge_result = (char *)malloc(sizeof(char) * 12);
		if (edge_result == NULL)
			return (NULL);
		ft_strlcpy(edge_result, "-2147483648", 12);
	}
	return (edge_result);
}

static int	allocate(int n)
{
	int	alloc;

	alloc = 1;
	if (n < 0)
		alloc++;
	while (n)
	{
		alloc++;
		n = n / 10;
	}
	return (alloc);
}

static void	reverse(char *str)
{
	char	tmp;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digit;
	int		sign;

	if (n == 0 || n == -2147483648)
		return (edge_case(n));
	result = (char *)malloc(sizeof(char) * allocate(n));
	if (result == NULL)
		return (NULL);
	digit = 0;
	sign = n;
	while (n)
	{
		result[digit] = (((n < 0) * (-n) + (n > 0) * n) % 10) + 48;
		n = n / 10;
		digit++;
	}
	if (sign < 0)
		result[digit++] = '-';
	result[digit] = '\0';
	reverse(result);
	return (result);
}
