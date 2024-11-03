/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:36 by hassende          #+#    #+#             */
/*   Updated: 2024/11/03 20:10:40 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"
# include "ft_printf/includes/ft_printf.h"

# define IMG_PXL 50

typedef struct s_info
{
	int     map_width;
	int     map_height;
	int		player;
	int     player_x;
	int     player_y;
	int		exit;
	int     exit_x;
	int     exit_y;
	int     collectibles;
	int     moves;
	char    **map;
}    t_info;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player_1;
	void	*player_2;
	void	*exit;
	void	*collectible;
}       t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_img	*imgs;
	t_info	*info;
}       t_mlx;


void    exit_error(char *error);
void	image_init(t_mlx *mlx);
void    hook_controls(t_mlx *mlx);
void	parser(t_mlx *mlx, char *file);
void	draw_map(t_mlx *mlx);
void	get_height_width(t_mlx *mlx);
int     close_window(t_mlx *mlx);
int		valid_character(char c);
int		all_one(char *line);
int		start_end_one(char *line);

# endif