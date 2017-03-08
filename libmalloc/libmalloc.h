/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:03:03 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/08 19:36:15 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMALLOC_H
# define FT_LIBMALLOC_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define BASIC 0
# define CLEAN 1
# define SET 2
# define MEMORY 10000

void	*ft_memzero(void *ptr, size_t size);
void	*ft_malloc(size_t size, int mode);
void	*ft_free(void *ptr);
void	ft_free_all(int mode);
void	*get_ptrbyid(size_t id);
void	**get_static(void);

#endif
