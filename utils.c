
# include "so_long.h"

int close_window(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	while (i < mlx->info->map_height)
	{
		free(mlx->info->map[i]);
		i++;
	}
	free(mlx->info);
	free(mlx);
	exit(0);
}

void	exit_error(char *error)
{
	perror(error);
	exit(1);
}