/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:19 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/29 20:20:45 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void 	ft_init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, LENGTH, HEIGHT, "RT");
	env->img = mlx_new_image(env->mlx, LENGTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->size, &env->endian);
}

static t_obj	*ft_init_objs()
{
	t_obj		*res;

	res = (t_obj *)malloc(sizeof(t_obj) * 3);
	res[0].type = SPHERE;
	res[0].radius = 2;
	res[0].pos = new_vector(0, 0, 0);
	res[0].rot = NULL;
	res[0].inv = NULL;
	res[0].rgb = (t_color){255, 255, 255, 0};

	res[1].type = SPHERE;
	res[1].radius = 2;
	res[1].pos = new_vector(0, -2, 0);
	res[1].rot = NULL;
	res[1].inv = NULL;
	res[1].rgb = (t_color) {255, 155, 155, 0};

	res[2].type = BACKSLASH;
	return (res);
}

int				main(void)
{
	t_obj	*objs;
	t_cam	*cam;
	t_env	env;
	t_vec	vec;

	ft_init_env(&env);
	vec = new_vector(0, 0, -10);
	objs = ft_init_objs();
	cam = init_cam(&vec, NULL, 60);
	raytrace(*cam, objs, env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_loop(env.mlx);
	return 0;
}
