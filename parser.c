
#include "so_long.h"

static void	check_content(char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
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
	}
	free(line);
	close(fd);
}

static void check_valid(char *map)
{
	char	*line;
	int		fd;
	size_t		i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Error\n");
	line = get_next_line(fd);
	i = 0;
	while (line[i])
		i++;
	while (line)
	{
		if (ft_strlen(line) != i && line[i - 1] != '\0')
			exit_error("Error\nMap not rectangular\n");	
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void read_map(char *file, t_info *info)
{
	// int		fd;
	// int		i;
	// char	*line;
	// char	**rtn;
	(void)info;

	check_valid(file);
	check_content(file);
	// fd = open(file, O_RDONLY);
	// line = get_next_line(fd);
	// return (rtn);
}

void parser(t_mlx *mlx, char *file)
{
	t_info *info;
	(void)mlx;

	info = malloc(sizeof(t_info));
	if (!info)
		exit_error("Malloc Faliure\n");
	/*info->map = */read_map(file, info);
	
}