/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:31 by hassende          #+#    #+#             */
/*   Updated: 2024/11/09 21:09:49 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_content(char *file)
{
	int		fd;
	int		i;
	int		n_lines;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	n_lines = 1;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (valid_character(line[i]) && line[i] != '\n')
				exit_error("Error\nInvalid character in map\n");
			i++;
		}
		free(line);
		line = get_next_line(fd);
		n_lines++;
	}
	free(line);
	close(fd);
	return (n_lines);
}

static char	*remove_nl(char *line)
{
	int		i;
	char	*str_rtn;

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
		exit_error("Error\nFirst Line and Last Line not all 1");
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

	n_lines = check_content(file) - 1;
	mlx->info->map = malloc((n_lines + 1) * sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("Error\nFile not found");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		mlx->info->map[i] = remove_nl(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	mlx->info->map[i] = NULL;
	close(fd);
	extract_map(mlx, n_lines);
}

void	parser(t_mlx *mlx, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(mlx);
		exit_error("Error\nFile not found");
	}
	close(fd);
	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
	{
		free(mlx);
		exit_error("Error\nFile not .ber");
	}
	mlx->info = malloc(sizeof(t_info));
	if (!mlx->info)
		exit_error("Malloc Faliure\n");
	store_map(file, mlx);
}
