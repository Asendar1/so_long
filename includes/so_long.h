/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:36 by hassende          #+#    #+#             */
/*   Updated: 2024/12/02 13:26:20 by hassende         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

# define IMG_PXL 50

typedef struct s_info
{
	int		map_width;
	int		map_height;
	int		player;
	int		player_x;
	int		player_y;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		moves;
	char	**map;
	char	**copy;
}		t_info;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player_down;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*exit;
	void	*collectible;
}		t_img;

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
}		t_mlx;

void	exit_error(char *error);
void	free_map(char **copy);
void	parser(t_mlx *mlx, char *file);
void	free_exit_error(t_mlx *mlx, const char *line);
void	how_many(t_mlx *mlx);
void	image_init(t_mlx *mlx);
void	hook_controls(t_mlx *mlx);
void	draw_map(t_mlx *mlx);
void	get_height_width(t_mlx *mlx);
void	flood_fill(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	destry_imgs(t_mlx *mlx);
void	free_exit(t_mlx *mlx);
void	win_state(t_mlx *mlx);
char	*get_next_line(int fd);
int		is_ber(char *file);
int		valid_character(char c);
int		all_one(char *line);
int		start_end_one(char *line);
int		close_window(t_mlx *mlx);

#endif
