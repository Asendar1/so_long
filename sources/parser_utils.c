/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:26 by hassende          #+#    #+#             */
/*   Updated: 2024/12/02 13:30:54 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_character(char c)
{
	if (c != '1' && c != 'P' && c != 'E' && c != 'C' && c != '0')
		return (0);
	return (1);
}

int	all_one(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		exit(1);
	}
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	start_end_one(char *line)
{
	size_t	i;

	i = ft_strlen(line);
	if (line[0] == '1' && line[i - 1] == '1')
		return (1);
	return (0);
}

void	norm_isbad(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'P')
	{
		info->player++;
		info->player_x = j;
		info->player_y = i;
	}
	if (info->map[i][j] == 'C')
		info->collectibles++;
	if (info->map[i][j] == 'E')
	{
		info->exit_x = j;
		info->exit_y = i;
		info->exit++;
	}
}

void	how_many(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->info->collectibles = 0;
	mlx->info->player = 0;
	mlx->info->exit = 0;
	while (mlx->info->map[i])
	{
		j = 0;
		while (mlx->info->map[i][j])
		{
			norm_isbad(mlx->info, i, j);
			j++;
		}
		i++;
	}
	if (mlx->info->player != 1 || mlx->info->exit != 1
		|| mlx->info->collectibles < 1)
	{
		free_exit(mlx);
		exit_error("Error\nWrong Number of Player, Exit or Collectibles");
	}
}
