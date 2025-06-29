/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyepes <cyepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:45:00 by cristian          #+#    #+#             */
/*   Updated: 2025/04/27 22:45:05 by cyepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_fractal_argument(char *av, char *str, char c, char n)
{
	int	i;

	if (!av || !av[0])
		return (0);
	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	fractal_set(t_fractol *f, char **av)
{
	if (check_fractal_argument(av[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (check_fractal_argument(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (check_fractal_argument(av[1], "burning ship", 'b', '3'))
		f->set = BURNING_SHIP;
	else
		help_user(f);
}

static void	validate_julia_params(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->kr = -0.70176;
		f->ki = -0.3842;
		return ;
	}
	if (ac == 3 || (!ft_strchr(av[2], '.')) || (!ft_strchr(av[3], '.')))
		help_user(f);
	f->kr = ft_strtod(av[2]);
	f->ki = ft_strtod(av[3]);
	if (f->kr > 2.0 || f->kr < -2.0 || f->ki >= 2.0 || f->ki <= -2.0)
		help_user(f);
}

static void	process_args(t_fractol *f, int ac, char **av)
{
	fractal_set(f, av);
	if (f->set != JULIA && ac > 3)
		help_user(f);
	else if (f->set == JULIA && ac > 5)
		help_user(f);
	validate_julia_params(f, ac, av);
	color_from_args(f, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	f = (t_fractol){0};
	if (ac < 2)
		help_user(&f);
	init_clean(&f);
	process_args(&f, ac, av);
	init(&f);
	fractol_render(&f);
	user_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, exit_fractol, &f);
	mlx_key_hook(f.win, key_controls, &f);
	mlx_mouse_hook(f.win, mouse_controls, &f);
	mlx_loop(f.mlx);
	return (0);
}
