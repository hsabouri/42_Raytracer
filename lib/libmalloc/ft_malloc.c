/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:07:19 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:30:30 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void	*ft_malloc(size_t size, int mode)
{
	static size_t	id = 0;
	void			**tab;
	void			*ptr;

	if (mode == SET)
	{
		id = size;
		return (NULL);
	}
	tab = get_malloc_static(id);
	if (!(ptr = (void *)malloc(size)))
	{
		perror("ft_malloc error:");
		exit(EXIT_FAILURE);
	}
	tab[id] = ptr;
	id += 1;
	if (mode == CLEAN)
		ptr = ft_memzero(ptr, size);
	return (ptr);
}

void	*get_ptrbyid(size_t id)
{
	void	**tab;

	tab = get_malloc_static(0);
	if (id >= MEMORY)
	{
		perror("ft_malloc error: id given to get_ptrbyid is out of range");
		exit(EXIT_FAILURE);
	}
	return (tab[id]);
}

void	*ft_free(void *ptr)
{
	void	**tab;
	size_t	i;

	if (ptr == NULL)
	{
		perror("ft_malloc error: ptr given to ft_free is setted to NULL");
		exit(EXIT_FAILURE);
	}
	tab = get_malloc_static(0);
	i = 0;
	while (i < 10000 && ptr != tab[i])
		i++;
	if (i == 10000)
		return (NULL);
	free(ptr);
	tab[i] = NULL;
	return (NULL);
}

void	ft_free_all(int mode)
{
	void	**tab;
	size_t	i;

	tab = get_malloc_static(0);
	i = 0;
	while (i < 10000)
	{
		if (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	ft_malloc(0, SET);
	if (mode == CLEAN)
		free(tab);
}
