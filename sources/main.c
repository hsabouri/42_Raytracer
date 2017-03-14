/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:19 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/09 23:04:52 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		draw(t_env *env)
{
	if (!(env->img = mlx_new_image(env->mlx, LENGTH, HEIGHT)))
		exit(0);
	if (!(env->addr = mlx_get_data_addr(env->img, &env->bpp,
					&env->size, &env->endian)))
		exit(0);
	if (env->pr_mesh)
		display_objs(env->objs);
	if (env->supersampling)
		test_ss_raytrace(env->cam, env->objs, *env);
	else
		raytrace(env->cam, env->objs, *env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
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
	env.cl = init_cl();
	vec = new_vector(0, 1, -10);
	env.cam = init_cam(vec, NULL, 66);
	mlx_expose_hook(env.win, expose, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop_hook(env.mlx, loop_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
