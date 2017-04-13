/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:36:43 by ple-lez           #+#    #+#             */
/*   Updated: 2017/04/13 18:19:49 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#define INTER(A, B, X) (A * (1 - (1 - cos(X * PI)) * 0.5) + B * X)

static double			noise(int x, int y)
{
	int					n;

	n = x + y * 57;
	n = (n << 13) ^ n;
	return (1.0 - ((n * ((n * n * 15731) + 789221) + 1376312589)
				& 0x7fffffff) / 1073741824.0);
}

static double			smooth(int x, int y)
{
	double				corner;
	double				edge;
	double				side;

	corner = (noise(x - 1, y - 1) + noise(x + 1, y - 1) +
			noise(x - 1, y + 1) + noise(x + 1, y + 1)) / 16;
	side = (noise(x - 1, y) + noise(x + 1, y) + noise(x, y + 1)) / 8;
	edge = noise(x, y) / 4;
	return (corner + side + edge);
}

static double			noise_handle(t_vec4 pos)
{
	int					intval[2];
	double				frval[2];
	double				val[4];
	double				res[2];

	intval[0] = (int)pos.x;
	intval[1] = (int)pos.y;
	frval[0] = pos.x - intval[0];
	frval[1] = pos.y - intval[1];
	val[0] = smooth(intval[0], intval[1]);
	val[1] = smooth(intval[0] + 1, intval[1]);
	val[2] = smooth(intval[0], intval[1] + 1);
	val[3] = smooth(intval[0] + 1, intval[1] + 1);
	res[0] = INTER(val[0], val[1], frval[0]);
	res[1] = INTER(val[2], val[3], frval[0]);
	return (INTER(res[0], res[1], frval[1]));
}

static double			perlin_handle(t_vec4 pos, int oct, double buf)
{
	int					i;
	double				coef;
	double				freq;
	double				amp;
	double				lac;

	coef = 0.0f;
	freq = 1.0f;
	amp = buf;
	lac = 2.0;
	i = 0;
	while (i < oct)
	{
		coef += noise_handle(vector_scale(pos, freq)) * amp;
		freq *= lac;
		amp *= buf;
		i++;
	}
	return (coef);
}

t_color					apply_perlin(t_obj obj, t_vec4 pos)
{
	static double		buf = 2.0;
	double				coef;
	t_color				res;

	res = obj.mat.rgb;
	coef = perlin_handle(pos, 4, buf);
	res = color_scale(res, coef);
	return (res);
}
