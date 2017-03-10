/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:43:21 by qduperon          #+#    #+#             */
/*   Updated: 2017/03/08 19:13:25 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdio.h>

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

double			scalar_product(t_vec4 v1, t_vec4 v2);
double			get_vector_len(t_vec4 v);

t_vec4			cross_product(t_vec4 v1, t_vec4 v2);
t_vec4			new_vector(double x, double y, double z);
t_vec4			normalize_vector(t_vec4 v1);
t_vec4			vector_add(t_vec4 v1, t_vec4 v2);
t_vec4			vector_scale(t_vec4 v1, double k);
t_vec4			vector_sub(t_vec4 v1, t_vec4 v2);

void			print_vector(t_vec4 v);

#endif
