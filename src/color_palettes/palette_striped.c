/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_striped.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:05:30 by cristian          #+#    #+#             */
/*   Updated: 2025/04/26 20:14:20 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color_stripe(t_fractol *f, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < f->iterations)
	{
		f->palette[i] = color;
		i += stripe;
	}
}

int	set_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

void	apply_color_zebra(t_fractol *f, int color)
{
	int	color2;

	color2 = set_percent_color(color, 50);
	set_color_stripe(f, color, 1);
	set_color_stripe(f, color2, 2);
	f->palette[f->iterations - 1] = 0;
}

void	apply_color_triad(t_fractol *f, int color)
{
	int		triad[2];

	triad[0] = set_percent_color(color, 33);
	triad[1] = set_percent_color(color, 66);
	set_color_stripe(f, color, 1);
	set_color_stripe(f, triad[0], 2);
	set_color_stripe(f, triad[1], 3);
	f->palette[f->iterations - 1] = 0;
}

void	apply_color_tetra(t_fractol *f, int color)
{
	int	tetra[3];

	tetra[0] = set_percent_color(color, 25);
	tetra[1] = set_percent_color(color, 50);
	tetra[2] = set_percent_color(color, 75);
	set_color_stripe(f, color, 1);
	set_color_stripe(f, tetra[0], 2);
	set_color_stripe(f, tetra[1], 3);
	set_color_stripe(f, tetra[2], 4);
	f->palette[f->iterations - 1] = 0;
}
