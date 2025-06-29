/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristian <cristian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:55:40 by cyepes            #+#    #+#             */
/*   Updated: 2025/04/28 11:39:40 by cristian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_plus(t_fractol *mlx)
{
	mlx->iterations += 14;
	if (mlx->iterations > MAX_ITERATIONS)
		mlx->iterations = MAX_ITERATIONS;
	restart_img(mlx);
	reapply_current_color(mlx);
}

void	iter_neg(t_fractol *mlx)
{
	mlx->iterations -= 14;
	if (mlx->iterations < 14)
		mlx->iterations = 14;
	restart_img(mlx);
	reapply_current_color(mlx);
}
