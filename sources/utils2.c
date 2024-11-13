/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:32:13 by hassende          #+#    #+#             */
/*   Updated: 2024/11/13 14:48:32 by hassende         ###   ########.fr       */
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
