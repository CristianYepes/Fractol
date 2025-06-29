/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_evets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 01:43:12 by cristian          #+#    #+#             */
/*   Updated: 2025/04/28 11:28:40 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scale_zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;
	double	width_r;
	double	height_i;

	center_r = (f->min_r + f->max_r) / 2.0;
	center_i = (f->min_i + f->max_i) / 2.0;
	width_r = (f->max_r - f->min_r) / 2.0;
	height_i = (f->max_i - f->min_i) / 2.0;
	width_r *= zoom;
	height_i *= zoom;
	f->min_r = center_r - width_r;
	f->max_r = center_r + width_r;
	f->min_i = center_i - height_i;
	f->max_i = center_i + height_i;
}

static void	shift_move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

static int	key_event_switch(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else if (keycode == KEY_THREE && mlx->set != BURNING_SHIP)
		mlx->set = BURNING_SHIP;
	else
		return (1);
	get_complex_plane(mlx);
	fractol_render(mlx);
	return (0);
}

int	key_controls(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		exit_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		iter_plus(mlx);
	else if (keycode == KEY_MINUS)
		iter_neg(mlx);
	else if (keycode == KEY_UP)
		shift_move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN)
		shift_move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT)
		shift_move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT)
		shift_move(mlx, 0.2, 'R');
	else if (keycode == KEY_SPACE)
		color_change(mlx);
	else if (!key_event_switch(keycode, mlx))
		return (1);
	else
		return (1);
	fractol_render(mlx);
	return (0);
}

int	mouse_controls(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		scale_zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			shift_move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			shift_move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			shift_move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			shift_move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		scale_zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_change(x, y, mlx);
	}
	else
		return (0);
	fractol_render(mlx);
	return (0);
}
