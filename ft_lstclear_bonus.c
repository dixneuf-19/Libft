/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:48:40 by mzary             #+#    #+#             */
/*   Updated: 2024/10/24 16:33:51 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (lst)
	{
		while (*lst)
		{
			nxt = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nxt;
		}
	}
}
