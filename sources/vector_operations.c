/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:36:14 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/26 15:08:59 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vec		vector_add(t_vec *v1, t_vec *v2)
{
	t_vec	res;
	
	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	res.w = 1;
	return (res);
}

t_vec		vector_sub(t_vec *v1, t_vec *v2)
{
	t_vec	res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	res.w = 1;
	return (res);
}

t_vec		vector_scale(t_vec *v1, double k)
{
	t_vec	res;

	res.x = v1->x * k;
	res.y = v1->y * k;
	res.z = v1->z * k;
	res.w = 1;
	return (res);
}
