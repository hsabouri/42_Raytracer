/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 01:37:11 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/12 17:29:14 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "rt.h"

/* Quit the program */

void		error(int code, char *str);
int			exit_clean(t_env *env);

/* Algorithm Functions */

int			raytrace(t_cam camera, t_obj *objs, t_env *env);
int			test_ss_raytrace(t_cam camera, t_obj *objs, t_env *env);
int			check_intersections(t_obj *objs, t_ray *ray);

/* Vector Functions	*/

t_vec4		vector_cap(t_vec4 vec, double min, double max);

/* Camera functions */

t_cam		change_mod(t_cam cam);
t_cam		cam_handle(t_cam cam, t_env *env);
t_cam		move_camera(t_cam cam, t_dir dir);
t_cam		rotate_cam(t_cam cam, t_quat rot);
t_cam		translate_cam(t_cam cam, t_vec4 tran);
t_cam		camera_control(t_cam cam, t_dir dir);

/* Light functions */

t_color		lights(t_obj obj, t_ray ray, t_env env, int depth);
t_vec4		lambert(t_obj obj, t_ray ray, t_lgt lgt);
t_color		apply_coef(t_color col, t_vec4 coef);
t_color		sum_lights(t_obj obj, t_ray ray, t_env env);
t_color		handle_reflect(t_ray ray, t_env env, int depth);
t_color		shadow_handler(t_obj *objs, t_ray ray, t_env env, t_color color);
int			shadows(t_obj *objs, t_ray ray, t_lgt lgt, int id);
double      specular(t_obj obj, t_ray ray, t_lgt lgt);

/* Limit functions */

double		limit_object(t_obj *obj, t_ray ray, double t1, double t2);

/* Material functions */

t_mat		new_material(t_color rgb, t_vec4 coef, int rf, double rr);

/* Ray functions */

t_ray		rotate_ray(t_ray ray, t_quat rot);
t_ray		reflect_ray(t_obj obj, t_ray ray);
t_ray		refract_ray(t_obj obj, t_ray ray);

/* Intersection functions */

double		intersect_cone(t_ray ray, t_obj *cone);
double		intersect_mesh(t_ray ray, t_obj *obj);
double		intersect_child(t_ray ray, t_obj *obj);
double		intersect_plane(t_ray ray, t_obj *plane);
double		intersect_sphere(t_ray ray, t_obj *sphere);
double		intersect_polygon(t_ray ray, t_obj poly);
double		intersect_cylinder(t_ray ray, t_obj *cylinder);

/* Math functions */

double		solve_quadra(t_obj *obj, t_ray ray, double a, double b, double c);
t_vec4      get_normal(t_ray ray, t_obj obj, t_vec4 pos);
t_vec4		normal_cylinder(t_vec4 pos, t_obj obj);
t_vec4		normal_plane(t_ray ray, t_obj obj);
t_vec4		normal_polygon(t_obj poly);

/* Initialization functions */

t_cam		init_cam(t_vec4 pos, t_quat rot, double fov);
t_ray		init_ray(t_cam *cam, int x, int y, t_env *env);
t_env		init_objs_lgts(int ac, char **av, t_env env);
t_env		init_env(int ac, char **av);
t_obj		init_skybox(t_env env);
t_ui 		*init_compnts(t_ui *ui, t_env env);

/* Mesh functions */

t_obj		create_mesh(t_color color, char *name);
t_obj		add_polygon(t_obj obj, t_obj poly);

/* Mlx functions */

t_img		pixel_put(t_img img, int x, int y, t_color color);
t_env		*del_square(t_env *env, int x, int y, int side);
t_img		init_img(t_img img, t_color color);
int			mouse(int x, int y, t_env *env);
int			keypress(int keycode, t_env *env);
int			keyrelease(int keycode, t_env *env);
int			button_press(int button, int x, int y, t_env *env);
int			button_release(int button, int x, int y, t_env *env);
t_env		*key_actions(t_env *env);
t_img		*create_img(t_img *res, int width, int height, void *mlx);

/* UV Mapping functions */

t_vec4		get_plane_pixel(t_obj obj, t_vec4 hit);
t_vec4		get_sphere_pixel(t_obj obj, t_vec4 hit);
t_vec4		get_cylinder_pixel(t_obj obj, t_vec4 hit);
t_color		get_pixel_from_uv(t_obj obj, t_vec4 pos);

/* Texture functions */

t_color		apply_perlin(t_obj obj, t_vec4 pos);
t_color		get_pixel_procedure(t_obj obj, t_vec4 pos);
t_color		get_pixel_color(t_obj obj, t_ray ray);
t_color		merge_color(t_color bg, t_color fg);
t_img		merge_img(t_img bg, t_img fg, int x, int y);
t_color		get_skybox(t_ray ray, t_env env);

/* Tools functions */

void		ft_fswap(double *a, double *b);
double      ft_min_max(double value, double min, double max);
t_color		filters(t_color color, t_env env);
t_color		color_scale(t_color col, double val);
void		c_log(char *str);
void		c_error(char *str, int code);
int			c_open_file(char *path);
t_color		int_to_color(int color);
t_color		add_colors(t_color c1, t_color c2);
int			color_to_int(t_color color);

/* Ui functions */

t_compnt	set_compnt_pos(int pos_x, int pos_y, t_compnt compnt);
t_compnt	set_compnt_size(unsigned int width, unsigned int height,\
			t_compnt compnt);
t_compnt	set_compnt_cols(t_color bg_default, t_color txt_color,\
			t_color bg_hover, t_compnt compnt);
int			ui(t_env *env);
t_ui 		*ui_draw(t_ui *ui, t_compnt compnt);
int			place_obj(int x, int y, t_env *env, t_obj obj);

/* Multi Thread and loops */

void		render_coroutine(t_env *env);
void		cancel_coroutine(t_env *env);
void 		*draw(void *arg);

/* TEMP */
void		temp_init(t_env *env);

#endif
