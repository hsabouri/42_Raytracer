/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:25:24 by qduperon          #+#    #+#             */
/*   Updated: 2017/03/07 11:43:12 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "vector.h"
# include <stdlib.h>

typedef struct s_quat
{
  double r;
  double i;
  double j;
  double k;
}             t_quat;

t_quat			*get_inverse(t_quat *q1);
t_quat			*new_quat(float radians, t_vec4 axis);
t_quat			*quat_mult(t_quat *q1, t_quat *q2);

t_vec4			quat_rot(t_quat *rot, t_vec4 *vec);

void			print_quat(t_quat *q1);

#endif
