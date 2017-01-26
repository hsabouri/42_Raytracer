/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:53:08 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/26 15:26:36 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double			scalar_product(t_vec *v1, t_vec *v2)
{
	double		res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

t_vec			new_vector(double x, double y, double z)
{
	t_vec		res;

	res = (t_vec){x, y, z, 1};
	return (res);
}

double			get_vector_len(t_vec *v)
{
	double		len;

	len = sqrt(scalar_product(v1, v1));
	return len;
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
	return res;
}

void			print_vector(t_vec *v)
{
	printf("Vector:\nX: %.5f\nY: %.5f\nZ: %.5f\nW: %.5f\n",
			v->x, v->y, v->z, v->w);
}
