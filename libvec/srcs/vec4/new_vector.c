/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:12:41 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 16:14:54 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

t_vec4 new_vector(double x, double y, double z)
{
  t_vec4 res;

  res = (t_vec4){x, y, z, 1};
  return (res);
}
