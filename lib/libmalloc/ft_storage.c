/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:03:03 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:39:06 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

static size_t	current_id(void)
{
	static size_t	id = 0;
	size_t			ret;

	ret = id;
	id += 1;
	return (ret);
}

t_array			new_array(size_t start_length, size_t sizeof_content)
{
	t_array ret;

	ret.id = current_id();
	ret.length = 0;
	ret.start_length = start_length;
	ret.value = (void *)ft_malloc(sizeof_content * start_length, CLEAN);
	return (ret);
}