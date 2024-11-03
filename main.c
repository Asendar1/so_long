/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:00 by hassende          #+#    #+#             */
/*   Updated: 2024/11/03 21:05:20 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*init_mlx(char *title, t_mlx *mlx)
{
	if (!mlx)
		exit_error("Malloc Faliure\n");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->info->map_width * IMG_PXL, mlx->info->map_height * IMG_PXL, title);
	mlx->img = mlx_new_image(mlx->mlx, mlx->info->map_width * IMG_PXL, mlx->info->map_height * IMG_PXL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
		&mlx->line_length, &mlx->endian);
	return (mlx);
}

void	pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx.addr + (y * mlx.line_length + x * (mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// TODO : Check for more than 1 player and exit. Add Controls. Add Moves Counter. Add Exit Condition. and Do the BONUS PART.
int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 2)
	{
		mlx = malloc(sizeof(t_mlx));
		parser(mlx, argv[1]);
		get_height_width(mlx);
		mlx = init_mlx(argv[1], mlx);
		image_init(mlx);
		draw_map(mlx);
		hook_controls(mlx);
		mlx_loop(mlx->mlx);
	}
	else
		exit_error("Usage: ./so_long *map*.bir");
}
