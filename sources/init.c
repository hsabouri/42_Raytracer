/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/09 22:31:26 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

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
	env.shadow = 0;
	env.pr_mesh = 0;
	env.sepia = 0;
	env.supersampling = 0;
	return (env);
}
