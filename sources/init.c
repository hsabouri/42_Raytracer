/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/04 12:21:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ui			*init_ui(t_env env)
{
	t_ui	*ui;

	ui = (t_ui *)ft_malloc(sizeof(t_ui), CLEAN);
	ui->keystatus = (int *)ft_malloc(sizeof(int) * 127, CLEAN);
	if (!(ui->img.img = mlx_new_image(env.mlx, LENGTH, HEIGHT)))
		exit(0);
	if (!(ui->img.addr = mlx_get_data_addr(ui->img.img, &ui->img.bpp,
					&ui->img.size, &ui->img.endian)))
		exit(0);
	if (!(ui->obj_map.img = mlx_new_image(env.mlx, LENGTH, HEIGHT)))
		exit(0);
	if (!(ui->obj_map.addr = mlx_get_data_addr(ui->obj_map.img, &ui->obj_map.bpp,
					&ui->obj_map.size, &ui->obj_map.endian)))
		exit(0);
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
	//mlx_put_image_to_window(env.mlx, env.win, ui->compnts[0].img.img);
	ui->compnts[0].draw_img = 1;
	ui->redraw = 1;
	return (ui);
}

void			init_texture(t_env *env)
{
	env->objs[0].mat.texture = create_xpm_img("textures/wall.xpm", *env);
	env->objs[1].mat.texture.type = NOISE;
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
	if (!(env.img.img = mlx_new_image(env.mlx, LENGTH, HEIGHT)))
		exit(0);
	if (!(env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bpp,\
	&env.img.size, &env.img.endian)))
		exit(0);
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
