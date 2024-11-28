/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:31 by hassende          #+#    #+#             */
/*   Updated: 2024/11/28 20:29:48 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*remove_nl(t_mlx *mlx, char *line)
{
	int		i;
	char	*str_rtn;

	if (valid_character(line))
	{
		free(line);
		free_exit_error(mlx ,"Error\nInvalid character in map");
	}
	str_rtn = ft_strdup(line);
	free(line);
	i = 0;
	while (str_rtn[i] != '\0')
	{
		if (str_rtn[i] == '\n')
		{
			str_rtn[i] = '\0';
			break ;
		}
		i++;
	}
	return (str_rtn);
}

static void	extract_map(t_mlx *mlx, int n_lines)
{
	int		i;
	size_t	len;

	i = 0;
	n_lines -= 1;
	if (!all_one(mlx->info->map[0]) || !all_one(mlx->info->map[n_lines]))
		free_exit_error(mlx, "Error\nFirst Line and Last Line not all 1");
	while (start_end_one(mlx->info->map[n_lines]) && n_lines >= 1)
		n_lines--;
	if (n_lines != 0)
	{
		free_exit(mlx);
		exit_error("Error\n map not surrounded by 1");
	}
	while (mlx->info->map[i] && mlx->info->map[i + 1])
	{
		len = ft_strlen(mlx->info->map[i]);
		if (len != ft_strlen(mlx->info->map[i + 1]))
		{
			free_exit(mlx);
			exit_error("Error\nMap not rectangular");
		}
		i++;
	}
	how_many(mlx);
}

static void	store_map(char *file, t_mlx *mlx)
{
	int		fd;
	int		i;
	char	*line;
	int		n_lines;

	n_lines = 0;
	mlx->info->map = ft_calloc((100), sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_exit_error(mlx, "Error\nFile Doesn't Exist");
	line = get_next_line(fd);
	i = 0;
	if (!line)
		free_exit_error(mlx, "Error\nEmpty File");
	while (line)
	{
		mlx->info->map[i] = remove_nl(mlx, line);
		line = get_next_line(fd);
		i++;
		n_lines++;
	}
	free(line);
	mlx->info->map[i] = NULL;
	close(fd);
	extract_map(mlx, n_lines);
}

void	parser(t_mlx *mlx, char *file)
{
	if (!is_ber(file))
	{
		free(mlx);
		exit_error("Error\nFile not .ber");
	}
	mlx->info = malloc(sizeof(t_info));
	if (!mlx->info)
		exit_error("Malloc Faliure\n");
	store_map(file, mlx);
}
