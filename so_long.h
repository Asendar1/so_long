
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

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"
# include "ft_printf/includes/ft_printf.h"

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_info	*info;
}       t_mlx;


void    exit_error(char *error);
int     close_window(t_mlx *mlx);
void    hook_controls(t_mlx *mlx);
void	parser(t_mlx *mlx, char *file);
int		valid_character(char c);
int		all_one(char *line);
int		start_end_one(char *line);
void	draw_map(t_mlx *mlx);

# endif