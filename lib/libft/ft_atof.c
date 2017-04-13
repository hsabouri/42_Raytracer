/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:15:31 by hsabouri          #+#    #+#             */
/*   Updated: 2017/04/13 17:42:32 by qduperon         ###   ########.fr       */
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

static	int		ft_sign(char *str)
{
	int		sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	return (sign);
}

static	double	first_part(char *str, double res, int sign)
{
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += (*str - '0') * sign;
		str++;
	}
	return (res);
}

double			ft_atof(const char *number)
{
	double	res;
	char	*str;
	int		power;
	int		sign;

	str = (char *)number;
	res = ft_dzero();
	sign = ft_sign(str);
	power = 1;
	while (!ft_isdigit(*str))
		str++;
	res = first_part(str, res, sign);
	while (ft_isdigit(*str))
		str++;
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
