/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/06 14:36:01 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		verify_data(t_env env)
{
	if (env.cam.fov > 180 || env.width < 50 || env.height < 50)
		error(0, "Corrupted scene file");
}

t_ui			*init_ui(t_env env)
{
	t_ui	*ui;

	ui = (t_ui *)ft_malloc(sizeof(t_ui), CLEAN);
	ui->width = env.width;
	ui->height = env.height;
	ui->keystatus = (int *)ft_malloc(sizeof(int) * 127, CLEAN);
	create_img(&ui->lay1, env.width, env.height, env.mlx);
	create_img(&ui->lay2, env.width, env.height, env.mlx);
	ui->lay1 = init_img(ui->lay1, (t_color){0, 0, 0, 255});
	ui->lay2 = init_img(ui->lay2, (t_color){0, 0, 0, 255});
	ui->obj_map = init_img(ui->obj_map, (t_color){255, 255, 255, 255});
	ui->n_compnts = 1;
	ui->compnts = (t_compnt *)ft_malloc(sizeof(t_compnt) * 1, CLEAN);
	ui->compnts[0].value = ft_strdup("Camera Mode");
	ui->compnts[0] = set_compnt_pos(30, 30, ui->compnts[0]);
	ui->compnts[0] = set_compnt_size(30, 30, ui->compnts[0]);
	ui->compnts[0] = set_compnt_cols((t_color){50, 50, 50, 0},\
		(t_color){255, 255, 255, 0}, (t_color){70, 70, 70, 0}, ui->compnts[0]);
	ui->compnts[0].idle = &idle_test;
	ui->compnts[0].hover = &hover_test;
	ui->compnts[0].action = &action_test;
	ui->compnts[0].img = create_xpm_img("assets/axes_xz.xpm", env);
	ui->compnts[0].draw_img = 1;
	ui->redraw = 1;
	return (ui);
}

t_env			init_objs_lgts(int ac, char **av, t_env env)
{
	int			fd;

	check_params(ac);
	fd = open_file(av[1]);
	env = parse(fd, env);
	verify_data(env);
	return (env);
}

t_env 			init_env(int ac, char **av)
{
	t_env env;
	t_vec4	vec;

	vec = new_vector(0, 0, -4);
	env.width = LENGTH;
	env.height = HEIGHT;
	env.mlx = mlx_init();
	env.cam = init_cam(vec, new_quat_null(), 66);
	env = init_objs_lgts(ac, av, env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, "RT");
	create_img(&env.img, env.width, env.height, env.mlx);
	env.redraw = 1;
	env.drawing = 0;
	env.shadow = 1;
	env.pr_mesh = 0;
	env.filter = NONE;
	env.supersampling = 0;
	env.ui = init_ui(env);
	env.frame = 0;
	return (env);
}
