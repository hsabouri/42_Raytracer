/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/19 00:24:57 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lgt			*init_lgts(t_env *env)
{
	t_lgt	*lgts;

	lgts = (t_lgt *)malloc(sizeof(t_lgt) * 4);
	env->n_lgt = 1;

	lgts[0].type = OMNI;
	lgts[0].pos = new_vector(-5, 4, -5);
	lgts[0].rgb = (t_color) {186, 186, 186, 0};

	lgts[1].type = OMNI;
	lgts[1].pos = new_vector(5, 4, -5);
	lgts[1].rgb = (t_color) {186, 0, 0, 0};
	
	lgts[2].type = OMNI;
	lgts[2].pos = new_vector(0, 5, -5);
	lgts[2].rgb = (t_color) {185, 45, 95, 0};
	
	lgts[3].type = NOLIGHT;
	return (lgts);
}

t_env 			init_env(void)
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, LENGTH, HEIGHT, "RT");
	env.lgt = init_lgts(&env);
	env.redraw = 1;
	env.shadow = 0;

	return (env);
}

t_obj			*init_objs(void)
{
	t_mat		mat;
	t_vec4		axis;
	t_obj		*res;

	axis = new_vector(0, 0, 1);
	res = (t_obj *)malloc(sizeof(t_obj) * 6);

	res[0].type = SPHERE;
	res[0].radius = 2;
	res[0].pos = new_vector(2, 4, 0);
	res[0].rot = NULL;
	res[0].inv = NULL;
	res[0].mat.rgb = (t_color){255, 255, 255, 0};
	res[0].mat.coef = new_vector(1, 0.8, 0.8);

	res[1].type = PLANE;
	res[1].radius = 1;
	res[1].pos = new_vector(0, -1, 0);
	res[1].rot = NULL;
	res[1].inv = NULL;
	res[1].dir = new_vector(0, 1, 0);
	res[1].mat.rgb = (t_color) {255, 255, 255, 0};
	res[1].mat.coef = new_vector(1, 1, 1);

	res[2].type = PLANE;
	res[2].radius = 1;
	res[2].rot = NULL;
	res[2].inv = NULL;
	res[2].pos = new_vector(0, 0, 10);
	res[2].dir = new_vector(0, 0, -1);
	res[2].mat.rgb = (t_color){255, 255, 255, 0};
	res[2].mat.coef = new_vector(1, 1, 1);
	
	res[3].type = BACKSLASH;
	return (res);
}
