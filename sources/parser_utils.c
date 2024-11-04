/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:26 by hassende          #+#    #+#             */
/*   Updated: 2024/11/04 19:29:03 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
		return (1);
	return (0);
}

int	all_one(char *line)
{
	int	i;

	i = 0;
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

void	how_many (t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->collectibles = 0;
	info->player = 0;
	info->exit = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
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
			j++;
		}
		i++;
	}
	if (info->player != 1 || info->exit != 1 || info->collectibles < 1)
		exit_error("Error\nWrong Number of Player, Exit or Collectibles");
}

