/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 01:37:11 by ple-lez           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/03/07 11:48:00 by ple-lez          ###   ########.fr       */
=======
/*   Updated: 2017/03/07 11:06:38 by pmartine         ###   ########.fr       */
>>>>>>> 71e82ebff364e04091b16541c3ca404f9aa94643
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "rt.h"

/* Quit the program */

void		error(int code, char *str);

/* Algorithm Functions */

int			raytrace(t_cam camera, t_obj *objs, t_env env);
int			test_ss_raytrace(t_cam camera, t_obj *objs, t_env env);
int			check_intersections(t_obj *objs, t_ray *ray, int depth);

/* Vector Functions	*/

t_vec4		vector_cap(t_vec4 vec, double min, double max);

/* Camera functions */

t_cam		move_camera(t_cam cam, t_dir dir);
t_cam		rotate_cam(t_cam cam, t_quat *rot);
t_cam		translate_cam(t_cam cam, t_vec4 tran);
t_cam		camera_control(t_cam cam, t_dir dir);

/* Light functions */

t_color		lights(t_obj obj, t_ray ray, t_env env, t_color color);
t_vec4		lambert(t_obj obj, t_ray ray, t_lgt lgt);
t_color		apply_lambert(t_color col, t_vec4 coef);
t_color		shadow_handler(t_obj *objs, t_ray ray, t_env env, t_color color);
int			shadows(t_obj *objs, t_ray ray, t_lgt lgt, int id);
double      specular(t_obj obj, t_ray ray, t_lgt lgt);

/* Material functions */

t_mat		new_material(t_color rgb, t_vec4 coef, int rf, double rr);

/* Ray functions */

t_ray		rotate_ray(t_ray ray, t_quat *rot);
t_ray		reflect_ray(t_obj obj, t_ray ray);
t_ray		refract_ray(t_obj obj, t_ray ray, double r);

/* Intersection functions */

double		intersect_cone(t_ray ray, t_obj cone);
double		intersect_mesh(t_ray ray, t_obj *obj);
double		intersect_polygon(t_ray ray, t_obj poly);
double		intersect_plane(t_ray ray, t_obj plane);
double		intersect_sphere(t_ray ray, t_obj sphere);
double		intersect_cylinder(t_ray ray, t_obj cylinder);

/* Math functions */

double		solve_quadra(double a, double b, double c);
t_vec4      get_normal(t_ray ray, t_obj obj, t_vec4 pos);
t_vec4		normal_plane(t_ray ray, t_obj obj);
t_vec4		normal_polygon(t_obj poly);

/* Initialization functions */

t_cam		init_cam(t_vec4 pos, t_quat *rot, double fov);
t_ray		init_ray(t_cam *cam, int x, int y);
t_env		init_objs_lgts(int ac, char **av, t_env env);
t_env		init_env(int ac, char **av);

/* Mesh functions */

t_obj		create_mesh(t_color color, char *name);
t_obj		add_polygon(t_obj obj, t_obj poly);

/* Mlx hook functions */

void		pixel_put(t_env env, unsigned int x, unsigned int y, t_color color);
int			key_hook(int keycode, t_env *env);

/* Tools functions */

void		print_mesh(t_obj obj);
double      ft_min_max(double value, double min, double max);

#endif
