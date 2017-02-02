/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:45:33 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/02 12:43:46 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_quat			new_quat(float radians, t_vec axis)
{
	float		sinf_rot;
	t_quat		res;

	sinf_rot = sinf(radians / 2.0);
	res.r = cosf(radians / 2.0);
	res.i = axis.x * sinf_rot;
	res.j = axis.y * sinf_rot;
	res.k = axis.z * sinf_rot;
	return (res);
}

static t_quat	get_inverse(t_quat *q1)
{
	t_quat		res;

	res.r = q1->r;
	res.i = -q1->i;
	res.j = -q1->j;
	res.k = -q1->k;
	return (res);
}

t_quat			quat_mult(t_quat *q1, t_quat *q2)
{
	t_quat		res;

	res.r = (q1->r * q2->r) - (q1->i * q2->i) - (q1->j * q2->j) - (q1->k * q2->k);
	res.i = (q1->r * q2->i) + (q1->i * q2->r) + (q1->j * q2->k) - (q1->k * q2->j);
	res.j = (q1->r * q2->j) + (q1->j * q2->r) + (q1->k * q2->i) - (q1->i * q2->k);
	res.k = (q1->r * q2->k) + (q1->k * q2->r) + (q1->i * q2->j) - (q1->j * q2->i);
	return (res);
}



t_vec			quat_rot(t_quat *rot, t_vec *vec)
{
	t_vec		res;
	t_quat		inv;
	t_quat		tmp;

	inv = get_inverse(rot);
	tmp = (t_quat){0, vec->x, vec->y, vec->z};
	tmp = quat_mult(rot, &tmp);
	tmp = quat_mult(&tmp, &inv);
	res = (t_vec){tmp.i, tmp.j, tmp.k, 1};
	return (res);
}

void			print_quat(t_quat *q1)
{
	printf("Quat:\nW: %.5f\nI: %.5f\nJ: %.5f\nK: %.5f\n",
			q1->r, q1->i, q1->j, q1->k);
}
