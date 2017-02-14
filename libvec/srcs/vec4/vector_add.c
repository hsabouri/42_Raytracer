/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:00:20 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 16:05:40 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4 vector_add(t_vec4 v1, t_vec4 v2)
{
  t_vec4 res;

  res.x = v1.x + v2.x;
  res.y = v1.y + v2.y;
  res.z = v1.z + v2.z;
  res.w = 1;
  return (res);
}
