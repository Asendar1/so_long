/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:17 by hassende          #+#    #+#             */
/*   Updated: 2024/11/05 16:00:43 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w)
	{
		move_up(mlx);
	}
	if (keycode == XK_s)
	{
		move_down(mlx);
	}
	if (keycode == XK_a)
	{
		move_left(mlx);
	}
	if (keycode == XK_d)
	{
		move_right(mlx);
	}
	return (0);
}

void	hook_controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
}
