/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_quat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:30:21 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 17:38:35 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quaternion.h"

t_quat			*new_quat(float radians, t_vec4 axis)
{
	float		sinf_rot;
	t_quat		*res;

	res = (t_quat *)malloc(sizeof(t_quat));
	sinf_rot = sinf(radians / 2.0);
	res->r = cosf(radians / 2.0);
	res->i = axis.x * sinf_rot;
	res->j = axis.y * sinf_rot;
	res->k = axis.z * sinf_rot;
	return (res);
}
