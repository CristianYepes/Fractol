/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyepes <cyepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:51:03 by cristian          #+#    #+#             */
/*   Updated: 2025/04/27 22:45:15 by cyepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_available_fractals(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tB - Burning Ship", 1);
	ft_putendl_fd("\e[36mUsage ej:\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m", 1);
}

void	describe_color_usage(void)
{
	ft_putendl_fd("\n+===========  Color Display  ==================+", 1);
	ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
	ft_putendl_fd("The hex color code must be formatted as RRGGBB:", 1);
	ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
	ft_putendl_fd("\tRed:\tFF0000\t\tGreen:\t00FF00", 1);
	ft_putendl_fd("\tBlue:\t0000FF\t\tYellow:\tFFFF00", 1);
	ft_putendl_fd("Other interesting colors:", 1);
	ft_putendl_fd("\tPurple:\t9933FF\t\tOrange:\tCC6600", 1);
	ft_putendl_fd("\tPink:\tFF3399\t\tTurquoise: 00FF80\t", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol <type> <color>", 1);
	ft_putendl_fd("\t\t./fractol M 0066FF\e[0m", 1);
	ft_putendl_fd("\nFor Julia, you can only specify colors after", 1);
	ft_putendl_fd("the starting values.", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J 0.285 0.01 CC6600\e[0m", 1);
}

void	user_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  ===============+", 1);
	ft_putendl_fd("Arrow keys\t\tmove view.", 1);
	ft_putendl_fd("scroll wheel\t\tzoom in and out.", 1);
	ft_putendl_fd("+/-\t\t\titerative details.", 1);
	ft_putendl_fd("Spacebar\t\tchange color schemes.", 1);
	ft_putendl_fd("Left click\t\tshift Fractol set(only Julia).", 1);
	ft_putendl_fd("1, 2, 3,\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
	ft_putendl_fd("+=============================================+\n", 1);
}

void	help_user(t_fractol *f)
{
	ft_putendl_fd("\n+================================================+", 1);
	ft_putendl_fd("|                    FRACT'OL                     |", 1);
	ft_putendl_fd("+================================================+\n", 1);
	show_available_fractals();
	describe_color_usage();
	clearup_exit(EXIT_FAILURE, f);
}
