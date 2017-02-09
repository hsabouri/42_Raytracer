/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 01:37:11 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/09 11:55:09 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "rt.h"

/* Algorithm Functions */

int			raytrace(t_cam camera, t_obj *objs, t_env env);
int			check_intersections(t_obj *objs, t_ray *ray);

/* Vector Functions	*/

t_vec		new_vector(double x, double y, double z);
t_vec		vector_add(t_vec v1, t_vec v2);
t_vec		vector_sub(t_vec v1, t_vec v2);
t_vec		vector_scale(t_vec v1, double k);
t_vec		normalize_vector(t_vec v);
t_vec		cross_product(t_vec v1, t_vec v2);
t_vec		quat_rot(t_quat *q1, t_vec *vec);
t_vec		vector_cap(t_vec vec, double min, double max);
double		scalar_product(t_vec v1, t_vec v2);
double		get_vector_len(t_vec v);
void		print_vector(t_vec v);

/* Quaternion functions */

t_quat		*new_quat(float radians, t_vec axis);
t_quat		*quat_mult(t_quat *q1, t_quat *q2);
t_quat		*get_inverse(t_quat *q1);
void		print_quat(t_quat *q1);

/* Camera functions */

t_cam		move_camera(t_cam cam, t_dir dir);
t_cam		rotate_cam(t_cam cam, t_quat *rot);
t_cam		translate_cam(t_cam cam, t_vec tran);
t_cam		camera_control(t_cam cam, t_dir dir);

/* Light functions */

t_color		lights(t_obj obj, t_ray ray, t_env env, t_color color);
t_vec		lambert(t_obj obj, t_ray ray, t_lgt lgt);
t_color		apply_lambert(t_color col, t_vec coef);
t_color		shadow_handler(t_obj *objs, t_ray ray, t_env env, t_color color);
int			shadows(t_obj *objs, t_ray ray, t_lgt lgt, int id);

/* Intersection functions */

double		intersect_cone(t_ray ray, t_obj cone);
double		intersect_plane(t_ray ray, t_obj plane);
double		intersect_sphere(t_ray ray, t_obj sphere);
double		intersect_cylinder(t_ray ray, t_obj cylinder);

/* Math functions */

double		solve_quadra(double a, double b, double c);
t_vec		normal_plane(t_ray ray, t_obj obj);

/* Initialization functions */

t_cam		init_cam(t_vec pos, t_quat *rot, double fov);
t_ray		init_ray(t_cam *cam, int x, int y);
t_obj		*init_objs(void);
t_env		init_env(void);

/* Mlx hook functions */

void		pixel_put(t_env env, unsigned int x, unsigned int y, t_color color);
int			key_hook(int keycode, t_env *env);

#endif
