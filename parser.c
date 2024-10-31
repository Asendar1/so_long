/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:31 by hassende          #+#    #+#             */
/*   Updated: 2024/10/31 11:28:43 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	extract_map(t_info *info, int n_lines)
{
	// int	i;

	// i = 0;
	n_lines -= 2;
	if (!all_one(info->map[0]) && !all_one(info->map[n_lines]))
		exit_error("Error\nFirst Line and Last Line not all 1");
	while (start_end_one(info->map[n_lines]) && n_lines >= 1)
		n_lines--;
	if (n_lines != 0)
		exit_error("Error\n map not surrounded by 1");
}

static void	store_map(char *file, t_info *info)
{
	int		fd;
	int		i;
	char	*line;
	int		n_lines;

	n_lines = check_content(file) - 1;
	info->map = malloc(n_lines * sizeof(char *));
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		info->map[i] = remove_nl(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	info->map[i] = NULL;
	close(fd);
	extract_map(info, n_lines);
}

void	parser(t_mlx *mlx, char *file)
{
	mlx->info = malloc(sizeof(t_info));
	if (!mlx->info)
		exit_error("Malloc Faliure\n");
	store_map(file, mlx->info);
}
