/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:15:31 by hsabouri          #+#    #+#             */
/*   Updated: 2017/02/15 18:08:03 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_dzero(void)
{
	double res;

	bzero(&res, sizeof(res));
	res = 0;
	return (res);
}

double			ft_atof(const char *number)
{
	double	res;
	char	*str;
	int		sign;
	int		power;
	
	str = (char *)number;
	res = ft_dzero();
	while (ft_isspace(*str))
		str++;
	sign = 1;
	power = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += (*str - '0') * sign;
		str++;
	}
	if (*str == '.' || *str == ',')
	{
		str++;
		while (ft_isdigit(*str))
		{
			power *= 10;
			res += ((double)(*str - '0') / (double)power) * sign;
			str++;
		}
	}
	return (res);
}
