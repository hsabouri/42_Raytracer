/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:19 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/05 16:36:42 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			*draw(void *arg)
{
	t_env *env;

	env = (t_env *)arg;
	env->drawing = 1;
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if (env->pr_mesh)
		display_objs(env->objs, env->n_obj);
	if (env->supersampling)
		test_ss_raytrace(env->cam, env->objs, env);
	else
		raytrace(env->cam, env->objs, env);
	env->drawing = 0;
	return (NULL);
}

static int		expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	env->ui->redraw = 1;
	return (0);
}

static int 		draw_loop(t_env *env)
{
	env->frame += 1;
	env = key_actions(env);
	if (env->redraw > 0 && env->drawing == 0)
	{
		render_coroutine(env);
		env->redraw -= 1;
		env->ui->redraw += 1;
	}
	if (env->ui->redraw > 0)
	{
		ui(env);
		env->ui->redraw -= 1;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->ui->img.img, 0, 0);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;
	t_vec4	vec;

	env = init_env(ac, av);
	vec = new_vector(0, 0, -4);
	env.cam = init_cam(vec, new_quat_null(), 66);
	mlx_expose_hook(env.win, expose, &env);
	mlx_loop_hook(env.mlx, draw_loop, &env);
	mlx_hook(env.win, KEYPRESSEVENT, KEYPRESSMASK, &keypress, &env);
	mlx_hook(env.win, KEYRELEASEEVENT, KEYRELEASEMASK, &keyrelease, &env);
	mlx_hook(env.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &exit_clean, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, &mouse, &env);
	mlx_hook(env.win, BUTTONPRESS, BUTTONPRESSMASK, &button_press, &env);
	mlx_hook(env.win, BUTTONRELEASE, BUTTONRELEASEMASK, &button_release, &env);
	mlx_loop(env.mlx);
	return (0);
}
