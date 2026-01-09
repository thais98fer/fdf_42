/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:07:00 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/09 19:59:04 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define ISO_ANGLE 0.523599
# define SCALE 20
# define KEY_ESC 65307

// **points matrix
// columns
// rows

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	error;
	int	double_error;
}	t_bresenham;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	t_mlx	mlx;
	t_img	img;
}	t_map;

// fdf.c
int		main(int argc, char **argv);

// read_map.c
int		ft_count_width(char *line);
void	ft_get_map_size(char *filename, t_map *map);
void	ft_allocate_points(t_map *map);
void	ft_fill_points(char *filename, t_map *map);
void	ft_read_map(char *filename, t_map *map);

// pixel.c
void	ft_put_pixel(t_img *img, int x, int y, int color);
int		ft_get_color(int z);
t_point	ft_isometric_proj(t_point p);

// draw.c
void	ft_draw_line(t_map *map, t_point p1, t_point p2);
void	ft_draw_neighbors(t_map *map, int x, int y);
void	ft_draw_map(t_map *map);

// hook.c
void	ft_free_map(t_map *map);
int		ft_close(t_map *map);
int		ft_key_hook(int keycode, t_map *map);

#endif
