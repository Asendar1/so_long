/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:32:13 by hassende          #+#    #+#             */
/*   Updated: 2024/11/20 18:02:44 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_exit_error(t_mlx *mlx, const char *line)
{
	free_map(mlx->info->map);
	free(mlx->info);
	free(mlx);
	perror(line);
	exit(01);
}

int	is_ber(char *file)
{
	char	*check;
	size_t	i;

	if (ft_strlen(file) < 4)
		return (0);
	i = ft_strlen(file) - 4;
	check = ft_substr(file, i, 4);
	if (ft_strncmp(check, ".ber", 4) != 0)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}
