/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:31:15 by hsabouri          #+#    #+#             */
/*   Updated: 2017/03/16 17:34:40 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_compnt	set_compnt_pos(int pos_x, int pos_y, t_compnt compnt)
{
	compnt.x = pos_x;
	compnt.y = pos_y;
	return (compnt);
}

t_compnt	set_compnt_size(unsigned int width, unsigned int height,\
t_compnt compnt)
{
	compnt.w = width;
	compnt.h = height;
	return (compnt);
}

t_compnt	set_compnt_cols(t_color bg_default, t_color txt_color,\
t_color bg_hover, t_compnt compnt)
{
	compnt.bg = bg_default;
	compnt.bg_hv = bg_hover;
	compnt.color = txt_color;
	return (compnt);
}

static t_compnt	ui_calls(t_compnt compnt, t_ui ui, t_env env)
{
	if (ui.mouse_x >= compnt.x && ui.mouse_y >= compnt.y &&\
		ui.mouse_x < compnt.x + compnt.w &&\
		ui.mouse_y < compnt.y + compnt.h)
	{
		if (compnt.hover)
			compnt = (*compnt.hover)((struct s_compnt)compnt, env);
		if (compnt.action && ui.click)
			compnt = (*compnt.action)((struct s_compnt)compnt, env);
	}
	else if (compnt.idle)
		compnt = (*compnt.idle)((struct s_compnt)compnt, env);
	return (compnt);
}

int				ui(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->ui->n_compnts)
	{
		env->ui->compnts[i] = ui_calls(env->ui->compnts[i], *env->ui, *env);
		env->ui->img = ui_draw(env->ui->img, env->ui->compnts[i]);
		i++;
	}
	return (0);
}