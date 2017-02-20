/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/20 11:33:18 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_lgt			*init_lgts(t_env *env)
{
	t_lgt	*lgts;

	lgts = (t_lgt *)malloc(sizeof(t_lgt) * 4);
	env->n_lgt = 3;

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

t_obj			*init_objs(int ac, char **av)
{
	t_obj		*res;
	int			fd;
	int			i = 0;
	
	check_params(ac);
	fd = open_file(av[1]);
	res = parse(fd);
	while (res[i].type != BACKSLASH)
	{
		res[i].rot = NULL;
		i++;
	}
	return (res);
}
