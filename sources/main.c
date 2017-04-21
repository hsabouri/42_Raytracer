/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <ple-lez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:24:19 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/21 17:06:35 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			*draw(void *arg)
{
	t_env *env;

	env = (t_env *)arg;
	env->drawing = 1;
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	raytrace(env->cam, env);
	env->drawing = 0;
	return (NULL);
}

static int		expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	env->ui->redraw = 1;
	return (0);
}

static int		draw_loop(t_env *env)
{
	env->frame += 1;
	env = key_actions(env);
	if (env->redraw > 0 && env->drawing == 0)
	{
		render_coroutine(env);
		env->redraw -= 1;
	}
	if (env->ui->draw)
		ui(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	if (env->ui->draw)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->ui->lay1.img, 0, 0);
		mlx_put_image_to_window(env->mlx, env->win, env->ui->lay2.img, 0, 0);
	}
	env->ui->last_click = env->ui->click;
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;

	env = init_env(ac, av);
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
