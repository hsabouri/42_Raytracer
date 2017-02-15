/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randomize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:51:25 by ple-lez           #+#    #+#             */
/*   Updated: 2017/02/14 18:08:15 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function to generate pseudo-random numbers,
** Using the Lehmer algorithm;
** To a better generation:
** add and mod must be coprime integers,
** fct - 1 must be a product of p, p being a prime divisor of mod,
** fct - 1 must be a product of 4 if mod is a multiple of 4;
** If mod is less than 2, the behavior is undefined
*/
#include "libft.h"

int			ft_randomize(int fct, int add, int mod, int gen)
{
	int i;
	int	*res;

	i = 1;
	res = (int *)malloc(sizeof(int) * gen);
	res[0] = (fct + add) % mod;
	while (i <= gen)
	{
		res[i] = ((fct * res[i - 1]) + add) % mod;
		i++;
	}
	return (res[gen]);
}
