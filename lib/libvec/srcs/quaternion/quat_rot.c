/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:32:20 by qduperon          #+#    #+#             */
/*   Updated: 2017/03/03 16:21:08 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quaternion.h"

t_vec4			quat_rot(t_quat rot, t_vec4 vec)
{
	const t_quat	inv = get_inverse(rot);
	t_vec4			res;
	t_quat			tmp;
	t_quat			tmp2;

	tmp.r = 0;
	tmp.i = vec.x;
	tmp.j = vec.y;
	tmp.k = vec.z;
	tmp2 = quat_mult(rot, tmp);
	tmp = quat_mult(tmp2, inv);
	res = (t_vec4){tmp.i, tmp.j, tmp.k, 1};
	return (res);
}
