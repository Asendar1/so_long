/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:11 by hassende          #+#    #+#             */
/*   Updated: 2024/11/04 22:41:24 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_height_width(t_mlx *mlx)
{
    int i;
    int j;
    
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

// static void	first_draw(t_mlx *mlx)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < mlx->info->map_height)
// 	{
// 		x = 0;
// 		while (x < mlx->info->map_width)
// 		{
// 			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, x * IMG_PXL, y * IMG_PXL);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_map(t_mlx *mlx)
{
	int y;
	int x;
	
	y = 0;
	mlx->info->moves = 0;
	// first_draw(mlx);
	while (y < mlx->info->map_height)
	{
		x = 0;
		while (x < mlx->info->map_width)
		{
			if (mlx->info->map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, x * IMG_PXL, y * IMG_PXL);
			if (mlx->info->map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->wall, x * IMG_PXL, y * IMG_PXL);
			if (mlx->info->map[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->player_down, x * IMG_PXL, y * IMG_PXL);
			if (mlx->info->map[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->exit, x * IMG_PXL, y * IMG_PXL);
			if (mlx->info->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->collectible, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		y++;
	}
}
