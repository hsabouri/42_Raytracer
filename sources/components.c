/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:08:36 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/10 18:19:34 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static t_compnt	compnts_default(t_compnt compnt, int x_offset, int y_offset)
{
	compnt = set_compnt_pos(x_offset, y_offset, compnt);
	compnt = set_compnt_size(30, 30, compnt);
	compnt = set_compnt_cols((t_color){50, 50, 50, 0},\
		(t_color){255, 255, 255, 0}, (t_color){90, 90, 90, 0}, compnt);
	compnt.draw_img = 1;
	return (compnt);
}

static t_ui		*init_compnts3(t_ui *ui, t_env env)
{
	ui->compnts[4].idle = idle_a;
	ui->compnts[4].hover = hover_a;
	ui->compnts[4].action = action_a;
	ui->compnts[4].draw_img = 1;
	ui->compnts[5] = ui->compnts[4];
	ui->compnts[6] = ui->compnts[4];
	ui->compnts[7] = ui->compnts[4];
	ui->compnts[4] = compnts_default(ui->compnts[4], 15, 60);
	ui->compnts[5] = compnts_default(ui->compnts[5], 15, 91);
	ui->compnts[6] = compnts_default(ui->compnts[6], 15, 122);
	ui->compnts[7] = compnts_default(ui->compnts[7], 15, 153);
	ui->compnts[4].img = parse_asset("assets/sphere.xpm", env);
	ui->compnts[5].img = parse_asset("assets/plane.xpm", env);
	ui->compnts[6].img = parse_asset("assets/cylinder.xpm", env);
	ui->compnts[7].img = parse_asset("assets/cone.xpm", env);
	ui->compnts[4].value = (t_obj *)ft_malloc(sizeof(t_obj), CLEAN);
	ui->compnts[5].value = (t_obj *)ft_malloc(sizeof(t_obj), CLEAN);
	ui->compnts[6].value = (t_obj *)ft_malloc(sizeof(t_obj), CLEAN);
	ui->compnts[7].value = (t_obj *)ft_malloc(sizeof(t_obj), CLEAN);
	((t_obj *)ui->compnts[4].value)->type = SPHERE;
	((t_obj *)ui->compnts[4].value)->mat.rgb = (t_color){255, 255, 255, 0};
	((t_obj *)ui->compnts[4].value)->mat.alpha = 0;
	((t_obj *)ui->compnts[4].value)->mat.reflect = -1.0;
	((t_obj *)ui->compnts[4].value)->mat.refract = -1.0;
	((t_obj *)ui->compnts[4].value)->mat.coef = new_vector(1, 1, 1);
	((t_obj *)ui->compnts[4].value)->mat.texture.type = NOTEX;
	((t_obj *)ui->compnts[4].value)->radius = 1;
	((t_obj *)ui->compnts[4].value)->rot = new_quat_null();
	((t_obj *)ui->compnts[4].value)->inv = get_inverse(new_quat_null());
	((t_obj *)ui->compnts[4].value)->pos = new_vector(0, 0, 0);
	((t_obj *)ui->compnts[4].value)->dir = new_vector(0, 1, 0);
	*((t_obj *)ui->compnts[5].value) = *(t_obj *)ui->compnts[4].value;
	*((t_obj *)ui->compnts[6].value) = *(t_obj *)ui->compnts[4].value;
	*((t_obj *)ui->compnts[7].value) = *(t_obj *)ui->compnts[4].value;
	((t_obj *)ui->compnts[5].value)->type = PLANE;
	((t_obj *)ui->compnts[6].value)->type = CYLINDER;
	((t_obj *)ui->compnts[7].value)->type = CONE;
	return (ui);
}

static t_ui		*init_compnts2(t_ui *ui, t_env env)
{
	ui->compnts[2].idle = &idle_c;
	ui->compnts[2].hover = &hover_c;
	ui->compnts[2].action = &action_c;
	ui->compnts[3] = ui->compnts[2];
	ui->compnts[2].value = ui->compnts + 3;
	ui->compnts[3].value = ui->compnts + 2;
	ui->compnts[2].id = 2;
	ui->compnts[3].id = 3;
	ui->compnts[2] = compnts_default(ui->compnts[2], 91, 15);
	ui->compnts[3] = compnts_default(ui->compnts[3], 122, 15);
	ui->compnts[2].img = parse_asset("assets/draft.xpm", env);
	ui->compnts[3].img = parse_asset("assets/render.xpm", env);
	ui->compnts[3].action(ui->compnts[3], &env);
	return (init_compnts3(ui, env));
}

t_ui 			*init_compnts(t_ui *ui, t_env env)
{
	ui->n_compnts = 8;
	ui->compnts = (t_compnt *)ft_malloc(sizeof(t_compnt) * 9, CLEAN);
	ui->compnts[0].idle = &idle_r;
	ui->compnts[0].hover = &hover_r;
	ui->compnts[0].action = &action_r;
	ui->compnts[0].draw_img = 1;
	ui->compnts[1] = ui->compnts[0];
	ui->compnts[0].value = ui->compnts + 1;
	ui->compnts[1].value = ui->compnts + 0;
	ui->compnts[0].id = 0;
	ui->compnts[1].id = 1;
	ui->compnts[0] = compnts_default(ui->compnts[0], 15, 15);
	ui->compnts[1] = compnts_default(ui->compnts[1], 46, 15);
	ui->compnts[0].img = parse_asset("assets/rotate.xpm", env);
	ui->compnts[1].img = parse_asset("assets/move.xpm", env);
	ui->compnts[1].action(ui->compnts[1], &env);
	return (init_compnts2(ui, env));
}
