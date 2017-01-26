/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:49:43 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/11 21:09:09 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxt;

	lst = *alst;
	while (lst)
	{
		nxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt;
	}
	*alst = NULL;
}
