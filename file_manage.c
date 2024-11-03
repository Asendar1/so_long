#include "so_long.h"

void	image_init(t_mlx *mlx)
{
	int    a;

	mlx->imgs = malloc(sizeof(t_img));
	mlx->imgs->wall = mlx_xpm_file_to_image(mlx->mlx, "textures/wall.xpm", &a, &a);
	mlx->imgs->floor = mlx_xpm_file_to_image(mlx->mlx, "textures/floor.xpm", &a, &a);
	mlx->imgs->player_1 = mlx_xpm_file_to_image(mlx->mlx, "textures/player-1.xpm", &a, &a);
	mlx->imgs->collectible = mlx_xpm_file_to_image(mlx->mlx, "textures/collectable.xpm", &a, &a);
	mlx->imgs->exit = mlx_xpm_file_to_image(mlx->mlx, "textures/exit.xpm", &a, &a);
}