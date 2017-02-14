/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:03:52 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/13 18:36:47 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4  cross_product(t_vec4 v1, t_vec4 v2)
{
  t_vec4  res;

  res.x = v1.y * v2.z - v1.z * v2.y;
  res.y = v1.z * v2.x - v1.x * v2.z;
  res.z = v1.x * v2.y - v1.y * v2.x;
  res = normalize_vector(res);
  return(res);
}
