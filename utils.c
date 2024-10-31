/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:43 by hassende          #+#    #+#             */
/*   Updated: 2024/10/31 11:37:57 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	while (i < mlx->info->map_height)
	{
		free(mlx->info->map[i]);
		i++;
	}
	free(mlx->info);
	free(mlx);
	exit(0);
}

void	exit_error(char *error)
{
	perror(error);
	exit(1);
}
