/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:03:03 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/13 17:46:12 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define DEFAULT 0
# define BASIC 0
# define CLEAN 1
# define SET 2
# define GET 0
# define MEMORY 10000

typedef struct	s_array
{
	size_t		id;
	void		*value;
	size_t		length;
	size_t		start_length;
}				t_array;

t_array			new_array(size_t start_length, size_t sizeof_content);

void			*ft_memzero(void *ptr, size_t start_length);
void			*ft_malloc(size_t size, int mode);
void			*ft_free(void *ptr);
void			ft_free_all(int mode);
void			*get_ptrbyid(size_t id);
void			**get_malloc_static(size_t current_id);

#endif
