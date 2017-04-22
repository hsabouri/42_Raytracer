/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:50:00 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/22 18:30:06 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			init_limits(t_env *env)
{
	env->objs[0].lmt.axis = (t_vec4){1, 0, 0, 0};
	env->objs[3].lmt.axis = (t_vec4){0, 1, 0, 0};
	env->objs[4].lmt.axis = (t_vec4){0, 1, 0, 0};
	env->objs[0].lmt.coef_max = (t_vec4){1, 0.5, 0.5, 0};
	env->objs[3].lmt.coef_max = (t_vec4){0, 2, 0, 0};
	env->objs[4].lmt.coef_max = (t_vec4){0, 2, 0, 0};
	env->objs[0].lmt.coef_min = (t_vec4){-1, -0.5, -0.5, 0};
	env->objs[3].lmt.coef_min = (t_vec4){0, -4, 0, 0};
	env->objs[4].lmt.coef_min = (t_vec4){0, -4, 0, 0};
	env->objs[3].lmt.mode = MOVEMENT;
	env->objs[4].lmt.mode = ROTATION;
	env->objs[0].ch_type = LIMIT;
	env->objs[4].ch_type = LIMIT;
	env->objs[3].ch_type = LIMIT;
}

static void		verify_data(t_env env)
{
	if (env.cam.fov > 180 || env.width < 50 || \
			env.height < 50 || env.n_obj <= 0)
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
	ui = init_compnts(ui, env);
	ui->color = (t_color){255, 255, 255, 0};
	ui->draw = 0;
	ui->click = 0;
	ui->last_click = 0;
	ui->delete = 0;
	ui->place.type = BACKSLASH;
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

t_env			init_env(int ac, char **av)
{
	t_env	env;
	t_vec4	vec;

	vec = new_vector(0, 0, -4);
	env.width = LENGTH;
	env.height = HEIGHT;
	env.ambient = 0.1;
	env.mlx = mlx_init();
	env.cam = init_cam(vec, new_quat_null(), 66);
	env = init_objs_lgts(ac, av, env);
	env.win = mlx_new_window(env.mlx, env.width, env.height, "RT");
	create_img(&env.img, env.width, env.height, env.mlx);
	env.img = init_img(env.img, (t_color){0, 0, 0, 0});
	env.sky = parse_asset("textures/snow_sky.xpm", env);
	env.objs[env.n_obj - 1] = init_skybox(env);
	env.redraw = 1;
	env.drawing = 0;
	env.shadow = 1;
	env.filter = NONE;
	env.ui = init_ui(env);
	env.render = 1;
	env.frame = 0;
	return (env);
}
