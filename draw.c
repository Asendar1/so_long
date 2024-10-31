/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:11 by hassende          #+#    #+#             */
/*   Updated: 2024/10/31 13:09:22 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_height_width(t_mlx *mlx)
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

void	draw_map(t_mlx *mlx)
{
	int width;
	int height;

	get_height_width(mlx);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "textures/wall.xpm", &width, &height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
