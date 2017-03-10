/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:36:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/03/10 18:59:41 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static inline double	find_prime(double x, double y)
{
	int					n;
	int					nn;

	n = (int)x + (int)y * 57;
	n = (n << 13) ^ n;
	nn = (n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
	return (1.0 - ((double)nn / 1073741824.0));
}

static inline double	interpolate(double a, double b, double x)
{
	double				ft;
	double				f;

	ft = x * PI;
	f = (1.0 - cos(ft)) * 0.5;
	return (a * (1.0 - f) + b * f);
}

double					perlin_noise(double x, double y)
{
	t_vec4				f;
	t_vec4				vec;
	t_vec4				inter;

	f.x = (int)x;
	f.y = (int)y;
	vec.x = find_prime(f.x    , f.y    );
	vec.y = find_prime(f.x + 1, f.y    );
	vec.z = find_prime(f.x    , f.y + 1);
	vec.w = find_prime(f.x + 1, f.y + 1);
	inter.x = interpolate(vec.x, vec.y, x - f.x);
	inter.y = interpolate(vec.z, vec.w, x - f.x);
	return interpolate(inter.x, inter.y, y - f.y);
}

double					apply_perlin(t_vec4 pos)
{
	int					oct;
	double				coef;
	double				freq;
	double				amp;

	oct = 0;
	coef = 0.0;
	while (oct < 2)
	{
		freq = pow(2, oct);
		amp = pow(1 / 2, oct);
		coef += perlin_noise(pos.x * freq, pos.y * freq) * amp;
		oct++;
	}
	coef += 1;
	coef /= 2.0;
	return (coef);
}
