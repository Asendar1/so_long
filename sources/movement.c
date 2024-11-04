#include "so_long.h"

static void   print_moves(t_mlx *mlx)
{
	char    *str;

	if (mlx->info->moves < 0 || !mlx->info->moves)
		mlx->info->moves = 0;
	str = ft_itoa(mlx->info->moves);
	write(1, "Moves: ", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void    move_up(t_mlx *mlx)
{
	if(mlx->info->map[mlx->info->player_y - 1][mlx->info->player_x] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->player_up, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL - 50);
	mlx->info->player_y--;
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'C')
{
        mlx->info->collectibles--;
        mlx->info->map[mlx->info->player_y][mlx->info->player_x] = '0';
    }
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'E' && mlx->info->collectibles == 0)
		mlx_string_put(mlx->mlx, mlx->win, 100, 100, 0, "You Win!");
	mlx->info->moves++;
	print_moves(mlx);
}
void    move_down(t_mlx *mlx)
{
	if(mlx->info->map[mlx->info->player_y + 1][mlx->info->player_x] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->player_down, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL + 50);
	mlx->info->player_y++;
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'C')
	{
		mlx->info->collectibles--;
		mlx->info->map[mlx->info->player_y][mlx->info->player_x] = '0';
	}
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'E' && mlx->info->collectibles == 0)
		mlx_string_put(mlx->mlx, mlx->win, 100, 100, 0, "You Win!");
	mlx->info->moves++;
	print_moves(mlx);
}

void    move_left(t_mlx *mlx)
{
	if(mlx->info->map[mlx->info->player_y][mlx->info->player_x - 1] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->player_left, mlx->info->player_x * IMG_PXL - 50, mlx->info->player_y * IMG_PXL);
	mlx->info->player_x--;
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'C')
	{
		mlx->info->collectibles--;
		mlx->info->map[mlx->info->player_y][mlx->info->player_x] = '0';
	}
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'E' && mlx->info->collectibles == 0)
		mlx_string_put(mlx->mlx, mlx->win, 100, 100, 0, "You Win!");
	mlx->info->moves++;
	print_moves(mlx);
}

void    move_right(t_mlx *mlx)
{
	if(mlx->info->map[mlx->info->player_y][mlx->info->player_x + 1] == '1')
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->floor, mlx->info->player_x * IMG_PXL, mlx->info->player_y * IMG_PXL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->imgs->player_right, mlx->info->player_x * IMG_PXL + 50, mlx->info->player_y * IMG_PXL);
	mlx->info->player_x++;
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'C')
	{
		mlx->info->collectibles--;
		mlx->info->map[mlx->info->player_y][mlx->info->player_x] = '0';
	}
	if (mlx->info->map[mlx->info->player_y][mlx->info->player_x] == 'E' && mlx->info->collectibles == 0)
		mlx_string_put(mlx->mlx, mlx->win, 100, 100, 0, "You Win!");
	mlx->info->moves++;
	print_moves(mlx);
}