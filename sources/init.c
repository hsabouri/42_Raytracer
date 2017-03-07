/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/03/07 12:06:42 by ple-lez          ###   ########.fr       */
=======
/*   Updated: 2017/03/07 11:18:59 by pmartine         ###   ########.fr       */
>>>>>>> 71e82ebff364e04091b16541c3ca404f9aa94643
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_env			init_objs_lgts(int ac, char **av, t_env env)
{
	int			fd;
	int			i = 0;
	
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
<<<<<<< HEAD
	env.pr_mesh = 0;

=======
	env.supersampling = 0;
>>>>>>> 71e82ebff364e04091b16541c3ca404f9aa94643
	return (env);
}
