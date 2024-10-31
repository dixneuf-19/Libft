/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:15:48 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 14:40:20 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *start, int len)
{
	char	*max;

	max = "9223372036854775807";
	while (*start == '0')
	{
		start++;
		len--;
	}
	if (len > 19)
		return (0);
	else if (len < 19)
		return (1);
	if (ft_strncmp(start, max, len) > 0)
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			sign;
	const char	*start;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	start = nptr;
	while ('0' <= *nptr && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	if (!check(start, nptr - start) && sign == 1)
		return (-1);
	else if (!check(start, nptr - start) && sign == -1)
		return (0);
	return (res * sign);
}
