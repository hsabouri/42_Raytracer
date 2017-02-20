/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 11:00:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/20 14:50:53 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

void	display_objs(t_obj *objs)
{
	unsigned int i;

	i = 0;
	while (objs[i].type != BACKSLASH)
	{
		objs[i].rot = NULL;
		objs[i].mat.reflect = 0;
		objs[i].mat.refract = 0.0;
		objs[i].lst = 0;
		printf("Object number : %d\n	Object name : %s\n", i, objs[i].name);
		printf("	Object color : %d %d %d\n",
			objs[i].mat.rgb.r,
			objs[i].mat.rgb.g,
			objs[i].mat.rgb.b);
		printf("	Object position : %f %f %f\n",
			objs[i].pos.x,
			objs[i].pos.y,
			objs[i].pos.z);
		printf("	Object direction : %f %f %f\n",
			objs[i].dir.x,
			objs[i].dir.y,
			objs[i].dir.z);
		if (objs[i].rot != NULL)
		{
			printf("	Object rotation : r: %f i: %f j: %f k: %f\n",
				objs[i].rot->r,
				objs[i].rot->i,
				objs[i].rot->j,
				objs[i].rot->k);
		}
		if (objs[i].inv != NULL)
		{
			printf("	Object inverse : r: %f i: %f j: %f k: %f\n",
				objs[i].rot->r,
				objs[i].rot->i,
				objs[i].rot->j,
				objs[i].rot->k);
		}
		i++;
	}
}
