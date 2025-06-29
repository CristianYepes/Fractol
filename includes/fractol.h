/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyepes <cyepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:01:55 by cristian          #+#    #+#             */
/*   Updated: 2025/04/27 23:46:33 by cyepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 500

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "keys.h"

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
	int		iterations;
}	t_fractol;

//exit_utils.c
void	clearup_exit(int exit_code, t_fractol *f);
int		show_error(char *str1, char *str2, int errno);
int		exit_fractol(t_fractol *mlx);
//help_user.c
void	show_available_fractals(void);
void	describe_color_usage(void);
void	user_controls(void);
void	help_user(t_fractol *f);
//parser.c
void	color_from_args(t_fractol *f, int ac, char **av);
double	ft_strtod(char *str);
//fractol.c
int		main(int ac, char **av);
//int.c
void	init_clean(t_fractol *f);
void	restart_img(t_fractol *f);
void	init(t_fractol *f);
void	get_complex_plane(t_fractol *f);
//color_palettes
void	color_change(t_fractol *f);
void	reapply_current_color(t_fractol *f); // Add this prototype
//palette_special
void	apply_color_opposites(t_fractol *f, int color);
void	apply_color_graphic(t_fractol *f, int color);
//palette_interpolated
void	apply_color_mono(t_fractol *f, int color);
void	apply_color_multiple(t_fractol *f, int colors[4], int n);
//palette_striped
int		set_percent_color(int color, double percent);
void	apply_color_zebra(t_fractol *f, int color);
void	apply_color_triad(t_fractol *f, int color);
void	apply_color_tetra(t_fractol *f, int color);
//fractol_render.c
void	fractol_render(t_fractol *f);
//math
int		burning_ship(double cr, double ci, t_fractol *f);
int		julia_change(int x, int y, t_fractol *f);
int		julia(double zr, double zi, t_fractol *f);
int		mandelbrot(double cr, double ci, t_fractol *f);
//fractol_events.c
int		key_controls(int keycode, t_fractol *mlx);
int		mouse_controls(int keycode, int x, int y, t_fractol *mlx);
//iter_utils.c
void	iter_plus(t_fractol *mlx);
void	iter_neg(t_fractol *mlx);
#endif
