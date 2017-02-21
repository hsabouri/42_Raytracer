/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:43:21 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/21 09:58:40 by hsabouri         ###   ########.fr       */
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

int			static_keeper(int new, int to_change);

int			open_file(char *path);
void		check_params(int ac);
void		usage(void);
void		display_objs(t_obj *objs);

t_lgt		*create_lgt(t_ltype type, char *name, t_lgt *lgts, size_t *n_lgt);
t_obj		*create_obj(t_type type, char *name, t_obj *objs, size_t *n_obj);
	
t_obj		*assign_objs(char *line, t_obj *objs, size_t *n_obj);
t_lgt		*assign_lgts(char *line, t_lgt *lgt, size_t *n_lgt);

t_vec4		parse_vec(char *str);
t_quat		*parse_quat(char *str, t_obj *obj);
t_color		parse_color(char *str);
double		parse_double(char *str);

t_env		parse(int fd, t_env env);

#endif
