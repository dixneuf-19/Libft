/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:48:24 by mzary             #+#    #+#             */
/*   Updated: 2024/11/01 04:20:38 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}
