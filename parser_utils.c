#include "so_long.h"

int valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
		return (1);
	return (0);
}

int	all_one(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int start_end_one(char *line)
{
	size_t i;

	i = ft_strlen(line);
	if (line[0] == '1' && line[i - 1] == '1')
		return (1);
	return (0);
}
