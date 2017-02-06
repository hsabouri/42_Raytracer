/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:30:56 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/06 01:35:53 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "defines.h"

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
 * files: vector_operation.s, vector_methods.c
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

t_vec				vector_add(t_vec v1, t_vec v2);

/* Vector sub:
 * Take vector v1 and vector v2,
 * returns a vector equals to v1 - v2
 */

t_vec				vector_sub(t_vec v1, t_vec v2);

/* Vector scale:
 * Take vector v1 and scalar k and return
 * a vector equals to v1 scaled by k;
 */

t_vec				vector_scale(t_vec v1, double k);

/* Scalar product:
 * Take vector v1 and vector v2
 * returns a double equals to
 * the scalar product of v1 x v2
 */

double				scalar_product(t_vec v1, t_vec v2);

/* Cross product:
 * Take vector v1 and vector v2
 * returns a vector perendicular
 * to v1 AND v2
 */

t_vec				cross_product(t_vec v1, t_vec v2);

/* New vector:
 * Construct a vector
 * with given coordinates
 */

t_vec				new_vector(double x, double y, double z);

/* Get Vector Len:
 * Returns the magnitude of
 * the given vector
 */

double				get_vector_len(t_vec v);

/* Normalize Vector:
 * Returns the normalized
 * given vector
 */

t_vec				normalize_vector(t_vec v);

/* Print vector:
 * Degub function, use it
 * to print the coordinates of
 * the given vector
 */

void				print_vector(t_vec v);


/* Quat is the structure
 * for quaternion:
 *
 * R is the real part of the number,
 * I, J and K are the imaginary part of
 * the hyper complex space
 *
 *  /!\  WARNING /!\
 *  I, J, and K should NEVER
 *  EVER be accessed direcctly :
 *  NO quat->i, quat->j or quat->k authorized
 *  UNLESS in a method of quaternion
 *
 *  FUNCTIONS should be used
 *  instead to modify these values
 *
 *	Think of these components
 *	as PRIVATE
 *
 *  ACCESSING IT DIRECTLY MAY CAUSE 
 *  BIG PROBLEMS IN MATH
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

/* New Quaternion
 *
 * Take the angle of rotation in radians
 * and the axis of rotation
 * (AKA vector(1, 0, 0) for x, etc..)
 *
 * Returns an unit quaternion
 */

t_quat				new_quat(float radians, t_vec axis);

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

/* Print quaternion
 *
 * Test function, use it
 * to print the values of q quat
 */

void				print_quat(t_quat *q1);

/* Cam is the structur for the camera
 *
 * Pos denotes the position,
 * Rot is the quternion corresponding
 * to the rotation of the camera
 * FOV is the... fov
 */

typedef struct		s_cam
{
	t_vec			pos;
	t_quat			*rot;
	double			fov;
	t_mode			control;
}					t_cam;

/* Init Cam
 *
 * file: camera.c
 *
 * Returns an allocated camera
 * with given rotation, position and fov
 *
 * By default you want:
 * pos as (0, 0, 0),
 * rotation as NULL
 * and fov as 60;
 */

t_cam				init_cam(t_vec pos, t_quat *rot, double fov);

/* Rotate Cam
 *
 * Rotate the camera
 * by the givem quaternion
 */

t_cam				rotate_cam(t_cam cam, t_quat *rot);
t_cam				translate_cam(t_cam cam, t_vec tran);
t_cam				move_camera(t_cam cam, t_dir dir);
t_cam				camera_control(t_cam cam, t_dir dir);

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

/* Init Ray
 * file: init.c
 *
 * Initialize a ray launched by the camera
 * into the given x and y pixel
 *
 * Note: Use this function for the camera rays
 * only
 */

t_ray				init_ray(t_cam *cam, int x, int y);

/* Env is the structure
 * for all variables and components
 * who need to be used through
 * the program
 */

typedef struct		s_lgt
{
	t_vec			pos;
	t_vec			hitpnt;
	t_vec			normal;
}					t_lgt;


/* Color structure
 * Equivalent to an int
 * The endianness is correct
 */

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

/* TEMPORARY
 * Obj is the test
 * structure for objects
 * at the moment
 */

/* Object class
 * is the same for every objects
 * radius : can be the radius of something or the d of other
 * rot is the quaternion
 * inv is the inverse of it
 */

typedef struct		s_obj
{
	t_type			type;
	double			radius;
	t_vec			dir;
	t_vec			pos;
	t_quat			*rot;
	t_quat			*inv;
	t_color			rgb;
}					t_obj;

t_obj				*init_objs(void);

/* Environnment structure
 * Contains all the data we need in loop_hook
 */

typedef struct		s_env
{
	t_lgt			lgt;
	t_cam			cam;
	t_obj			*objs;
	char			*addr;
	void			*mlx;
	void			*win;
	void			*img;
	int				redraw;
	int				endian;
	int				size;
	int				bpp;
}					t_env;

t_env 				init_env(void);

double				solve_quadra(double a, double b, double c);
int					raytrace(t_cam camera, t_obj *objs, t_env env);
double				intersect_sphere(t_ray *ray, t_obj sphere);
double				intersect_plane(t_ray *ray, t_obj plane);
double				intersect_cone(t_ray *ray, t_obj cone);
double				intersect_cylinder(t_ray *ray, t_obj cylinder);

t_vec				normal_plane(t_ray ray, t_obj obj);

/*
 * MiniLibX related function
 */

/* Puts a pixel in env.img[]
 */

void				pixel_put(t_env env, unsigned int x, unsigned int y,
					t_color color);
int					key_hook(int keycode, t_env *env);


double				lambert(t_obj obj, t_ray ray, t_lgt lgt);
t_color				apply_lambert(t_color col, double l);

#endif
