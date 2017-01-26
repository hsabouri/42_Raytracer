/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:45:33 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/26 17:12:45 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"



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
	double		x;
	double		y;
	double		z;
	t_vec		res;

	x = 2 * ((-rot->j * rot->j + -rot->k * rot->k) * vec->x
			+ (rot->i * rot->j - rot->r * rot->k) * vec->y
			+ (rot->r * rot->j + rot->i * rot->k) * vec->z) + vec->x;
	y = 2 * ((rot->r * rot->k + rot->i * rot->j) * vec->x
			+ (-rot->i * rot->i - rot->k * rot->k) * vec->y
			+ (rot->j * rot->k - rot->r * rot->j) * vec->z) + vec->y;
	z = 2 * ((rot->i * rot->k - rot->r * rot->j) * vec->x
			+ (rot->r * rot->i + rot->j * rot->k) * vec->y
			+ (-rot->i * rot->i + -rot->j * rot->j) * vec->z) + vec->z;
	res = new_vector(x, y, z);
	return (res);
}
