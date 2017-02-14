/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:31:50 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 17:32:10 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quaternion.h"

t_quat			*quat_mult(t_quat *q1, t_quat *q2)
{
	t_quat		*res;

	res = (t_quat *)malloc(sizeof(t_quat));
	res->r = (q1->r * q2->r) - (q1->i * q2->i) - (q1->j * q2->j) - (q1->k * q2->k);
	res->i = (q1->r * q2->i) + (q1->i * q2->r) + (q1->j * q2->k) - (q1->k * q2->j);
	res->j = (q1->r * q2->j) + (q1->j * q2->r) + (q1->k * q2->i) - (q1->i * q2->k);
	res->k = (q1->r * q2->k) + (q1->k * q2->r) + (q1->i * q2->j) - (q1->j * q2->i);
	return (res);
}
