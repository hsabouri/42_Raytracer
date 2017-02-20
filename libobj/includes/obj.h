/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:43:21 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/20 11:06:27 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <libft.h>
# include <rt.h>

int			open_file(char *path);
void		check_params(int ac);
void		usage(void);
void		display_objs(t_obj *objs);
t_vec4		parse_vec(char *str);
t_color		parse_color(char *str);
double		parse_double(char *str);
t_obj		*parse(int fd);

#endif
