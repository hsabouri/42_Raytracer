/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/19 17:02:58 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			init_texture(t_env *env)
{	
	env->objs[0].mat.texture = create_xpm_img("textures/wall.xpm", *env);
	env->objs[1].mat.texture.type = CHECKER;
	env->objs[2].mat.texture = create_xpm_img("textures/earth.xpm", *env);
}

t_env			init_objs_lgts(int ac, char **av, t_env env)
{
	int			fd;
	
	check_params(ac);
	fd = open_file(av[1]);
	env = parse(fd, env);
	return (env);
}

t_env 			init_env(int ac, char **av)
{
	t_env env;

	env.mlx = mlx_init();
	env = init_objs_lgts(ac, av, env);
	env.win = mlx_new_window(env.mlx, LENGTH, HEIGHT, "RT");
	env.redraw = 1;
	env.shadow = 1;
	env.pr_mesh = 0;
	env.filter = NONE;
	env.supersampling = 0;
	return (env);
}
