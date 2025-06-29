/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyepes <cyepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:29:30 by cristian          #+#    #+#             */
/*   Updated: 2025/04/27 23:27:47 by cyepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	space_sign_0x(char *color)
{
	int	i;

	i = 0;
	while (ft_isspace(color[i]))
		i++;
	if (color[i] == '+')
		i++;
	if (color[i] == '0' && (color[i + 1]
			&& (color[i + 1] == 'x' || color[i + 1] == 'X')))
		i += 2;
	return (i);
}

static int	hex_to_int_color(t_fractol *f, char *color)
{
	int	i;
	int	digit_count;
	int	n;

	n = 0;
	i = 0;
	i = space_sign_0x(color);
	digit_count = 0;
	while (color[i] && ft_ishexdigit(color[i]))
	{
		if (ft_isdigit(color[i]))
			n = (n * 16) + (color[i] - '0');
		else if (color[i] >= 'A' && color[i] <= 'F')
			n = (n * 16) + (color[i] - 'A' + 10);
		else if (color[i] >= 'a' && color[i] <= 'f')
			n = (n * 16) + (color[i] - 'a' + 10);
		i++;
		digit_count++;
	}
	if (digit_count == 6 && !color[i])
		return (n);
	else
		help_user(f);
	return (-1);
}

void	color_from_args(t_fractol *f, int ac, char **av)
{
	if (f->set == JULIA && ac == 5)
		f->color = hex_to_int_color(f, av[4]);
	else if (f->set != JULIA && ac == 3)
		f->color = hex_to_int_color(f, av[2]);
	if (ac == 2 || (f->set == JULIA && ac == 4))
		f->color = 0x80BFFF;
}

static int	space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_strtod(char *str)
{
	int		i;
	double	result;
	int		is_neg;
	double	div;

	result = 0;
	div = 0.1;
	is_neg = 1;
	i = space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (result * is_neg);
}
