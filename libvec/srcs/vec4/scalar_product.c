/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:56:28 by qduperon          #+#    #+#             */
/*   Updated: 2017/02/14 15:59:24 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector.h"

inline double scalar_product(t_vec4 v1, t_vec4 v2)
{
  return(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
