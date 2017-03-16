/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:19 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/16 17:00:29 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		draw(t_env *env)
{
	if (!(env->img.img = mlx_new_image(env->mlx, LENGTH, HEIGHT)))
		exit(0);
	if (!(env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bpp,
					&env->img.size, &env->img.endian)))
		exit(0);
	if (env->pr_mesh)
		display_objs(env->objs);
	if (env->supersampling)
		test_ss_raytrace(env->cam, env->objs, *env);
	else
		raytrace(env->cam, env->objs, *env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	mlx_destroy_image(env->mlx, env->img.img);
	return (0);
}

static int		expose(t_env *env)
{
	env->redraw = 1;
	return (0);
}

static int		loop_hook(t_env *env)
{
	if (env->redraw)
	{
		draw(env);
		env->redraw = 0;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;
	t_vec4	vec;

	env = init_env(ac, av);
	//env.cl = init_cl();
	vec = new_vector(0, 1, -10);
	env.cam = init_cam(vec, NULL, 66);
	mlx_expose_hook(env.win, expose, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
