/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:33:41 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/17 14:58:18 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_env	*draw_col_rect(struct s_compnt compnt, t_env *env, t_color col)
{
	int x;
	int y;

	y = compnt.y + compnt.h;
	while (y < compnt.y + compnt.h + 5)
	{
		x = compnt.x;
		while (x < compnt.x + compnt.w)
		{
			pixel_put(env->ui->lay2, x, y, col);
			x++;
		}
		y++;
	}
	return (env);
}

t_compnt		action_col(struct s_compnt compnt, t_env *env)
{
	int x;
	int y;

	x = env->ui->mouse_x - compnt.x;
	y = env->ui->mouse_y - compnt.y;
	env->ui->color = ((t_color *)compnt.img.addr)[y * compnt.img.width + x];
	return (compnt);
}

t_compnt		hover_col(struct s_compnt compnt, t_env *env)
{
	int		x;
	int		y;
	t_color	color;

	compnt.status = HOVER;
	x = env->ui->mouse_x - compnt.x;
	y = env->ui->mouse_y - compnt.y;
	color = ((t_color *)compnt.img.addr)[y * compnt.img.width + x];
	draw_col_rect(compnt, env, color);
	return (compnt);
}

t_compnt		idle_col(struct s_compnt compnt, t_env *env)
{
	compnt.status = IDLE;
	draw_col_rect(compnt, env, env->ui->color);
	return (compnt);
}
