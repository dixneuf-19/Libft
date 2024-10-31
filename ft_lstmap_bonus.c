/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzary <mzary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:49:48 by mzary             #+#    #+#             */
/*   Updated: 2024/10/31 16:15:06 by mzary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elt;
	t_list	*start;
	int		first;

	first = 0;
	if (!lst || !f)
		return (lst);
	while (lst)
	{
		elt = ft_lstnew((*f)(lst->content));
		if (elt == NULL)
		{
			if (!first)
				ft_lstclear(&start, del);
			return (NULL);
		}
		if (first++ == 0)
			start = elt;
		else
			ft_lstadd_back(&start, elt);
		lst = lst->next;
	}
	return (start);
}
