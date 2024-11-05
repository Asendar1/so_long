/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:43 by hassende          #+#    #+#             */
/*   Updated: 2024/11/05 16:50:09 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destry_imgs(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->imgs->wall);
	mlx_destroy_image(mlx->mlx, mlx->imgs->floor);
	mlx_destroy_image(mlx->mlx, mlx->imgs->player_down);
	mlx_destroy_image(mlx->mlx, mlx->imgs->player_up);
	mlx_destroy_image(mlx->mlx, mlx->imgs->player_left);
	mlx_destroy_image(mlx->mlx, mlx->imgs->player_right);
	mlx_destroy_image(mlx->mlx, mlx->imgs->collectible);
	mlx_destroy_image(mlx->mlx, mlx->imgs->exit);
}

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->imgs)
	{
		destry_imgs(mlx);
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

void	free_exit(t_mlx *mlx)
{
	free_map(mlx->info->map);
	free(mlx->info);
	free(mlx);
}

void	exit_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(1);
}
