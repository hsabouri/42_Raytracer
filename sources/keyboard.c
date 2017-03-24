/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:20 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 15:15:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		keypress(int keycode, t_ui *ui)
{
	if (keycode < 127 && keycode >= 0)
		(ui->keystatus)[keycode] = 1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		keyrelease(int keycode, t_ui *ui)
{
	if (keycode < 127 && keycode >= 0)
		(ui->keystatus)[keycode] = 0;
	return (0);
}