/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:15:12 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 16:18:59 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4 normalize_vector(t_vec4 v)
{
  t_vec4 res;
  double len;

  len = 1.0 / get_vector_len(v);
  res.x = v.x * len;
  res.y = v.y * len;
  res.z = v.z * len;
  res.w = 1;
  return (res);
}
