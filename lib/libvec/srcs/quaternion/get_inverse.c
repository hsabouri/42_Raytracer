/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:31:07 by qduperon          #+#    #+#             */
/*   Updated: 2017/03/03 15:44:47 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/quaternion.h"

t_quat			get_inverse(t_quat q1)
{
	t_quat	res;

	res.r = q1.r;
	res.i = -q1.i;
	res.j = -q1.j;
	res.k = -q1.k;
	return (res);
}
