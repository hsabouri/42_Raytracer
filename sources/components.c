/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:08:36 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/07 16:56:49 by hsabouri         ###   ########.fr       */
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
	return (ui);
}

t_ui 			*init_compnts(t_ui *ui, t_env env)
{
	ui->n_compnts = 5;
	ui->compnts = (t_compnt *)ft_malloc(sizeof(t_compnt) * 5, CLEAN);
	ui->compnts[0].idle = &idle_r;
	ui->compnts[0].hover = &hover_r;
	ui->compnts[0].action = &action_r;
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
