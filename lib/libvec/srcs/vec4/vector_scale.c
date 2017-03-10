/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:00:40 by qduperon          #+#    #+#             */
/*   Updated: 2017/03/08 19:09:42 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4	vector_scale(t_vec4 v1, double k)
{
	t_vec4	res;

	res.x = v1.x * k;
	res.y = v1.y * k;
	res.z = v1.z * k;
	res.w = 1;
	return (res);
}
