/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:30:56 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/26 17:12:41 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# define PI 3.141592653
# define EPSILON pow(10, -6)
# define HEIGHT 600
# define LENGTH 600

/* Vec is the vector struct;
 * 4 coordinates for homogeneous coordinates:
 * x, y, z denotes the respective axis
 * w should always be equal to one
 */

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec;

/* Vector Operations
 * file: vector_operation.s
 * Contain all operations of vectors
 *
 * Note 1: Vectors should always be dereferenced
 * for performance issues
 *
 * Note 2: The w component of the resultings vectors
 * should always be one
 */

/* Vector add:
 * Take vector v1 and vector v2 and return
 * a vector corresponding to the addition
 * of the 2 given vectors
 */

t_vec				vector_add(t_vec *v1, t_vec *v2);

/* Vector sub:
 * Take vector v1 and vector v2,
 * returns a vector equals to v1 - v2
 */

t_vec				vector_sub(t_vec *v1, t_vec *v2);

/* Vector scale:
 * Take vector v1 and scalar k and return
 * a vector equals to v1 scaled by k;
 */

t_vec				vector_scale(t_vec *v1, double k);

/* Vector methods
 * file: vector_methods.c
 * Contain all method needed to create
 * and manipulate vectors
 *
 * Note 1: The w component of the results is one
 *
 * Note 2: Vectors should always be dereferenced
 * for performance issues
 */

/* Scalar product:
 * Take vector v1 and vector v2
 * returns a double equals to
 * the scalar product of v1 x v2
 */

double				scalar_product(t_vec *v1, t_vec *v2);

/* New vector:
 * Construct a vector
 * with given coordinates
 */

t_vec				new_vector(double x, double y, double z);

/* Get Vector Len:
 * Returns the magnitude of
 * the given vector
 */

double				get_vector_len(t_vec *v);

/* Normalize Vector:
 * Returns the normalized
 * given vector
 */

t_vec				normalize_vector(t_vec *v);

/* Print vector:
 * Degub function, use it
 * to print the coordinates of
 * the given vector
 */

void				print_vector(t_vec *v);

/* Ray is the structure for
 * ray components:
 * Basically everything from camera
 * to lights
 *
 * org is the vector of the coordinates
 * for the origin of the ray
 *
 * dir is the vector representing
 * the direction of the ray in 3 dimensions
 *
 * t is the scalar needed to get the distance
 * By default it is set to EPSILON
 */ 

typedef struct		s_ray
{
	t_vec			org;
	t_vec			dir;
	double			t;
}					t_ray;

/* Quat is the structure
 * for quaternion:
 *
 * R is the real part of the number,
 * I, J and K are the imaginary part of
 * the hyper complex space
 */

typedef struct		s_quat
{
	double			r;
	double			i;
	double			j;
	double			k;
}					t_quat;

/* Quaternion Operations
 * File: quaternion_operations.c
 *
 * Cover the range of operations on quaternions
 *
 * Note: All the quaternions should be dereferenced
 * for performance issues
 */

/* Quaternion Multiplication
 *
 * Take quaternions q1 and q2
 * and return the quaternion
 * equal to q1 x q2
 */

t_quat				quat_mult(t_quat *q1, t_quat *q2);

/* Quaternion  Rotation
 *
 * Take Quaternion rot and Vector vec
 * And returns another vector
 * corresponding to the rotation
 * of vec by rot
 */

t_vec				quat_rot(t_quat *q1, t_vec *vec);

#endif
