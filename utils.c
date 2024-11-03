/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:43 by hassende          #+#    #+#             */
/*   Updated: 2024/11/03 20:44:44 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_mlx *mlx)
{
    int i;

    i = 0;
    if (mlx->imgs)
    {
        if (mlx->imgs->wall)
            mlx_destroy_image(mlx->mlx, mlx->imgs->wall);
        if (mlx->imgs->floor)
            mlx_destroy_image(mlx->mlx, mlx->imgs->floor);
        if (mlx->imgs->player_1)
            mlx_destroy_image(mlx->mlx, mlx->imgs->player_1);
        if (mlx->imgs->exit)
            mlx_destroy_image(mlx->mlx, mlx->imgs->exit);
        if (mlx->imgs->collectible)
            mlx_destroy_image(mlx->mlx, mlx->imgs->collectible);
    }
    if (mlx->img)
        mlx_destroy_image(mlx->mlx, mlx->img);
    mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
    free(mlx->mlx);
    while (i < mlx->info->map_height)
    {
        free(mlx->info->map[i]);
        i++;
    }
    free(mlx->info->map);
    free(mlx->info);
    free(mlx->imgs);
    free(mlx);
    exit(0);
}

void	exit_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}
