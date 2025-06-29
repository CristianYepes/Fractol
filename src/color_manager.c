/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:45:53 by cristian          #+#    #+#             */
/*   Updated: 2025/04/29 21:09:21 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_change_special(t_fractol *f)
{
	if (f->color == 0xFFFFFF)
		f->color = 0x999999;
	if (f->color_pattern == 5)
		apply_color_opposites(f, f->color);
	else if (f->color_pattern == 6)
		apply_color_graphic(f, f->color);
	else if (f->color_pattern == 7)
		apply_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

static void	color_change_striped(t_fractol *f)
{
	if (f->color_pattern == 2)
		apply_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		apply_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		apply_color_tetra(f, f->color);
	else
		color_change_special(f);
}

void	reapply_current_color(t_fractol *f)
{
	int	alt_color;

	if (f->color == 0x000000)
		alt_color = 0x666666;
	else
		alt_color = f->color;
	if (f->color_pattern == 0)
		apply_color_mono(f, alt_color);
	else if (f->color_pattern == 1)
		apply_color_multiple(f, (int [4]){0x000000, alt_color,
			set_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else if (f->color_pattern == 2)
		apply_color_zebra(f, f->color);
	else if (f->color_pattern == 3)
		apply_color_triad(f, f->color);
	else if (f->color_pattern == 4)
		apply_color_tetra(f, f->color);
	else if (f->color_pattern == 5)
		apply_color_opposites(f, f->color);
	else if (f->color_pattern == 6)
		apply_color_graphic(f, f->color);
	else if (f->color_pattern == 7)
		apply_color_multiple(f, (int [8]){0xFF0000, 0xFF7F00, 0xFFFF00,
			0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3, 0xFFFFFF}, 8);
}

void	color_change(t_fractol *f)
{
	f->color_pattern = (f->color_pattern + 1) % 8;
	restart_img(f);
	if (f->color == 0x000000)
		f->color = 0x333333;
	if (f->color_pattern == 0)
		apply_color_mono(f, f->color);
	else if (f->color_pattern == 1)
		apply_color_multiple(f, (int [4]){0x000000, f->color,
			set_percent_color(f->color, 50), 0xFFFFFF}, 4);
	else
		color_change_striped(f);
}
