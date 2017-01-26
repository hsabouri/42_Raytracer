/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-lez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:08:46 by ple-lez           #+#    #+#             */
/*   Updated: 2015/12/10 18:42:56 by ple-lez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnegnbr_base(int n, int b)
{
	if (n <= -10)
	{
		ft_putnegnbr_base(n / b, b);
		ft_putnegnbr_base(n % b, b);
	}
	else if (n >= -9)
		ft_putchar(-n + '0');
	else
		ft_putchar(-n + 'A');
}

void		ft_putnbr_base(int n, int b)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnegnbr_base(n, b);
	}
	else if (n >= b)
	{
		ft_putnbr_base(n / b, b);
		ft_putnbr_base(n % b, b);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else
		ft_putchar(n + 'A');
}
