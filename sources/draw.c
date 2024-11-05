/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:11 by hassende          #+#    #+#             */
/*   Updated: 2024/11/05 16:06:26 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_height_width(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->info->map[i])
	{
		j = 0;
		while (mlx->info->map[i][j] != '\0')
			j++;
		i++;
	}
	mlx->info->map_height = i;
	mlx->info->map_width = j;
}

void	draw(t_mlx *mlx, int x, int y)
{
	if (mlx->info->map[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor,
			x * IMG_PXL, y * IMG_PXL);
	if (mlx->info->map[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->wall,
			x * IMG_PXL, y * IMG_PXL);
	if (mlx->info->map[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->imgs->player_down, x * IMG_PXL, y * IMG_PXL);
	if (mlx->info->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->imgs->exit, x * IMG_PXL, y * IMG_PXL);
	if (mlx->info->map[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->imgs->collectible, x * IMG_PXL, y * IMG_PXL);
}

void	draw_map(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	mlx->info->moves = 0;
	while (y < mlx->info->map_height)
	{
		x = 0;
		while (x < mlx->info->map_width)
		{
			draw(mlx, x, y);
			x++;
		}
		y++;
	}
}
