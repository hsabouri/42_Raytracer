/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:23:05 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/09 18:14:39 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnegnbr(int n)
{
	if (n <= -10)
	{
		ft_putnegnbr(n / 10);
		ft_putnegnbr(n % 10);
	}
	else
		ft_putchar(-n + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnegnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
