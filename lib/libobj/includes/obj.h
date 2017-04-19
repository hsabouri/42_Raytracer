/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:43:21 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/19 18:04:37 by hsabouri         ###   ########.fr       */
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
# include "../../includes/rt.h"

typedef struct		s_uint3
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
}					t_uint3;

int					static_keeper(int new, int to_change);

int					open_file(char *path);
void				check_params(int ac);
void				usage(void);

t_env				create_lgt(t_ltype type, char *name, t_env env);
t_env				create_obj(t_type type, char *name, t_env env);
t_obj				obj_default(t_type type, char *name);
t_obj				optimesh2000(t_obj obj, t_env env);

t_env				add_poly_to_last(char *line, t_env env);
t_env				create_vrt(char *line, t_env env);
t_img				create_xpm_img(char *path, t_env env);
t_obj				add_polygon(t_obj obj, t_obj poly);

t_env				objs(char *line, t_env env);
t_env				lgts(char *line, t_env env);
t_env				meshs(char *line, t_env env);
t_env				env_feed(char *line, t_env env);

t_vec4				parse_vec(char *str);
t_quat				parse_quat(char *str, t_quat *inv);
t_color				parse_color(char *str);
double				parse_double(char *str);
t_img				parse_asset(char *path, t_env env);
t_ttype				type_of_objs(char *str);

t_env				parse(int fd, t_env env);
t_env				parse_pipeline(t_env env, char *line, char *line2);

#endif
