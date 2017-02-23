/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:32:01 by pmartine          #+#    #+#             */
/*   Updated: 2017/02/23 16:37:25 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_min_max(double value, double min, double max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
	return (value);
}
