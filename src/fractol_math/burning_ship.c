/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:21:05 by cristian          #+#    #+#             */
/*   Updated: 2025/04/29 21:08:17 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_fabs(double cr)
{
	if (cr < 0)
		return (-cr);
	else
		return (cr);
}

int	burning_ship(double cr, double ci, t_fractol *f)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < f->iterations)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = ft_fabs(zr);
		zi = ft_fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}
