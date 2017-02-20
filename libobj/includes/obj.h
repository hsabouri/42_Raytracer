/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <hsabouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:43:21 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/19 09:28:49 by hsabouri         ###   ########.fr       */
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

int			open_file(const char *path);
void		check_params(int ac, char **av);
void		usage(void);
t_vec4		parse_vec(char *str);
t_color		parse_color(char *str);
t_obj		*parse(int fd);

#endif
