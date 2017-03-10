/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:33:38 by ple-lez           #+#    #+#             */
/*   Updated: 2016/09/01 15:59:12 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define MAX_FD 256
# define STR glob->str
# define RET glob->ret
# define BUFF glob->buff
# define TMP glob->tmp
# include <fcntl.h>
# include "libft.h"

typedef struct	s_glob
{
	int			ret;
	char		*str[MAX_FD];
	char		*buff;
	char		*tmp;
}				t_glob;

int				get_next_line(int const fd, char **line);
#endif
