/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:53:08 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/29 18:35:44 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

inline double	scalar_product(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec			new_vector(double x, double y, double z)
{
	t_vec		res;

	res = (t_vec){x, y, z, 1};
	return (res);
}

inline double	get_vector_len(t_vec *v)
{
	return(sqrt(scalar_product(v, v)));
}

t_vec			normalize_vector(t_vec *v)
{
	t_vec		res;
	double		len;

	len = 1.0 / get_vector_len(v);
	res.x = v->x * len;
	res.y = v->y * len;
	res.z = v->z * len;
	res.w = 1;
	return (res);
}

t_vec			cross_product(t_vec *v1, t_vec *v2)
{
	t_vec		res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	res = normalize_vector(&res);
	return (res);
}

void			print_vector(t_vec *v)
{
	printf("Vector:\nX: %.5f\nY: %.5f\nZ: %.5f\nW: %.5f\n",
			v->x, v->y, v->z, v->w);
}
