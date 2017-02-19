/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/19 04:28:32 by ple-lez          ###   ########.fr       */
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
	lgts[1].pos = new_vector(2, 4, -6);
	lgts[1].rgb = (t_color) {186, 186, 0, 0};
	
	lgts[2].type = OMNI;
	lgts[2].pos = new_vector(0, 5, 5);
	lgts[2].rgb = (t_color) {185, 45, 195, 0};
	
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
	t_color		rgb;
	t_obj		*res;
	t_obj		poly;

	res = (t_obj *)malloc(sizeof(t_obj) * 1);
	
	rgb = (t_color){255, 255, 255, 0};
	res[0] = create_mesh(rgb);
	poly.type = POLYGON;
	poly.vert[0] = new_vector(2, 4, 2);
	poly.vert[1] = new_vector(-1, 3, 0);
	poly.vert[2] = new_vector(1, 2, 0);
	res[0] = add_polygon(res[0], poly);
	
	res[1].type = BACKSLASH;
	return (res);
}
