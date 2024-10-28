
# include "so_long.h"


t_mlx *init_mlx(char *title, t_mlx *mlx)
{
    if (!mlx)
        exit_error("Malloc Faliure\n");
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, 800, 600, title);
    mlx->img = mlx_new_image(mlx->mlx, 800, 600);
    mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
    return (mlx);
}

void    pixel_put(t_mlx mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx.addr + (y * mlx.line_length + x * (mlx.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int main (int argc, char **argv)
{
    t_mlx   *mlx;

    if (argc == 2)
    {
        mlx = malloc(sizeof(t_mlx));
        mlx = init_mlx(argv[1], mlx);
        parser(mlx, argv[1]);
        hook_controls(mlx);
        mlx_loop(mlx->mlx);
    }
    else
        exit_error("Usage: ./so_long *maps*.bir \n");
}