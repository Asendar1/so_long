
# include "so_long.h"

int close_window(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx, mlx->img);
    mlx_destroy_window(mlx->mlx, mlx->win);
    mlx_destroy_display(mlx->mlx);
    free(mlx->mlx);
    free(mlx->img);
    free(mlx);
    exit(0);
}

void    exit_error(char *error)
{
    perror(error);
    exit(1);
}