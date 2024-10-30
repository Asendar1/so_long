
# include "so_long.h"

static void get_height_width(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while(mlx->info->map[i])
	{
		j = 0;
		while(mlx->info->map[i][j] != '\0')
			j++;
		i++;
	}
	mlx->info->map_height = i;
	mlx->info->map_width = j;
}

void	draw_map(t_mlx *mlx)
{
	get_height_width(mlx);
	
}