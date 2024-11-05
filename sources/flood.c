/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:09:14 by hassende          #+#    #+#             */
/*   Updated: 2024/11/05 16:38:12 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flooder(t_info *info, int x, int y, int *collect_check)
{
	if (x < 0 || y < 0 || x >= info->map_width || y >= info->map_height)
		return ;
	if (info->copy[y][x] == '1' || info->copy[y][x] == 'V')
		return ;
	if (info->copy[y][x] == 'E')
		info->exit = 0;
	if (info->copy[y][x] == 'C')
		(*collect_check)--;
	info->copy[y][x] = 'V';
	flooder(info, x + 1, y, collect_check);
	flooder(info, x - 1, y, collect_check);
	flooder(info, x, y + 1, collect_check);
	flooder(info, x, y - 1, collect_check);
}

static char	**copy_map(t_info *info)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (info->map_height + 1));
	if (!copy)
		exit_error("Malloc Failure\n");
	while (info->map[i])
	{
		copy[i] = ft_strdup(info->map[i]);
		if (!copy[i])
			exit_error("Malloc Failure\n");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	free_map(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

void	flood_fill(t_mlx *mlx)
{
	int		collect_check;

	mlx->info->copy = copy_map(mlx->info);
	collect_check = mlx->info->collectibles;
	flooder(mlx->info, mlx->info->player_x,
		mlx->info->player_y, &collect_check);
	if (collect_check != 0 || mlx->info->exit != 0)
	{
		free_map(mlx->info->map);
		free_map(mlx->info->copy);
		free(mlx->info);
		free(mlx);
		exit_error("Error\nInvalid map, exit or collectibles unreachable");
	}
	free_map(mlx->info->copy);
}
