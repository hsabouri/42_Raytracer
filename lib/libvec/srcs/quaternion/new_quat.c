/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:30:21 by qduperon          #+#    #+#             */
/*   Updated: 2017/04/13 17:54:31 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quaternion.h"

t_quat			new_quat(float radians, t_vec4 axis)
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

t_quat			new_quat_null(void)
{
	const float		radians = 0;
	const t_vec4	axis = (t_vec4){0, 0, 0, 0};
	float			sinf_rot;
	t_quat			res;

	sinf_rot = sinf(radians / 2.0);
	res.r = cosf(radians / 2.0);
	res.i = axis.x * sinf_rot;
	res.j = axis.y * sinf_rot;
	res.k = axis.z * sinf_rot;
	return (res);
}
