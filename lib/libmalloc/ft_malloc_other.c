/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 09:16:24 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:37:31 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

static void		**ft_copy(size_t size, void **src, void **dst)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void			**get_malloc_static(size_t current_id)
{
	static void		**tab = NULL;
	static size_t	size = 10000;
	void			**tmp;

	if (tab == NULL)
	{
		if (!(tab = (void **)malloc(MEMORY * sizeof(void *))))
		{
			perror("ft_malloc error:");
			exit(EXIT_FAILURE);
		}
	}
	if (current_id >= size)
	{
		if (!(tmp = (void **)malloc((size + 10000) * sizeof(void *))))
		{
			perror("ft_malloc error:");
			exit(EXIT_FAILURE);
		}
		tmp = ft_copy(size, tab, tmp);
		size += 10000;
		free(tab);
		tab = tmp;
	}
	return (tab);
}
