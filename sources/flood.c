#include "so_long.h"

static void flooder(t_info *info, int x, int y, int *collect_check, char **copy)
{
	if (x < 0 || y < 0 || x >= info->map_width || y >= info->map_height)
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'V')
		return ;
	if (copy[y][x] == 'E')
		info->exit = 0;
	if (copy[y][x] == 'C')
		(*collect_check)--;
	copy[y][x] = 'V';
	flooder(info, x + 1, y, collect_check, copy);
	flooder(info, x - 1, y, collect_check, copy);
	flooder(info, x, y + 1, collect_check, copy);
	flooder(info, x, y - 1, collect_check, copy);
}

static char **copy_map(t_info *info)
{
	int 	i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (info->map_height + 1));
	if (!copy)
		exit_error("Malloc Failure\n");
	while (info->map[i])
	{
		copy[i] = ft_strdup(info->map[i]);
		if (!copy[i])
			exit_error("Malloc Failure\n");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void free_map(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

void	flood_fill(t_mlx *mlx)
{
	int		collect_check;
	char	**copy;

	copy = copy_map(mlx->info);
	collect_check = mlx->info->collectibles;
	flooder(mlx->info, mlx->info->player_x, mlx->info->player_y, &collect_check, copy);
	if (collect_check != 0 || mlx->info->exit != 0)
	{
		// destry_imgs(mlx);
		// free(mlx->imgs);
		// free(mlx->info->map);
		// free(mlx->info);
		// free(mlx);
		// free_map(copy);
		exit_error("Error\nInvalid map, exit or collectibles unreachable");
	}
	free_map(copy);
}