/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:01:03 by ple-lez           #+#    #+#             */
/*   Updated: 2017/01/27 17:22:52 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		solve_quadra(double a, double b, double c)
{
	double	d;
	double	t1;
	double	t2;

	d = (b * b) - (4.0 * a * c);
	if (d < 0.0)
		return (0);
	else
	{
		t1 = (-b - sqrt(d)) / (2.0 * a);
		t2 = (-b + sqrt(d)) / (2.0 * a);
		if (t1 > EPSILON)
			return t1;
		else if (t2 > EPSILON)
			return t2;		
	}
	return (0);
}
