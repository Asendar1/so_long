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
	printf("line at all_one: %s\n",line);
	while(line[i-1])
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

	printf("line at start_end_one: %s\n",line);
	i = ft_strlen(line);
	if (line[0] == '1' && line[i] == '1')
		return (1);
	return (0);
}
