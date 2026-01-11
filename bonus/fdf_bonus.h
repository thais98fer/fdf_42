/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:07:00 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 04:42:35 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define ISO_ANGLE 0.523599
# define WIN_W 1920
# define WIN_H 1000
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define KEY_ESC 65307
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_P 112
# define KEY_I 105
# define KEY_O 111
# define KEY_R 114
# define KEY_Q 113
# define KEY_E 101
# define KEY_Z 122
# define KEY_X 120
# define KEY_C 99
# define KEY_V 118
# define KEY_SPACE 32

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL,
	CONIC
}	t_projection;

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
	int				width;
	int				height;
	float			scale;
	float			z_scale;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
	int				offset_x;
	int				offset_y;
	t_point			**points;
	t_img			img;
	t_mlx			mlx;
	t_projection	projection;
	float			zoom;
	float			rotate_x;
	float			rotate_y;
	float			rotate_z;
	int				translate_x;
	int				translate_y;
}	t_map;

// fdf.c
int		main(int argc, char **argv);
void	ft_reset_view(t_map *map);
void	ft_init(t_map *map);

// read_map.c
void	ft_get_map_size(char *filename, t_map *map);
void	ft_allocate_points(t_map *map);
void	ft_fill_row(t_map *map, char *line, int y);
void	ft_fill_points(char *filename, t_map *map);
void	ft_read_map(char *filename, t_map *map);

// pixel.c
void	ft_put_pixel(t_img *img, int x, int y, int color);
int		ft_get_color(int z);
t_point	ft_isometric_proj(t_map *map, t_point p);
int		ft_interpolate_color(int c1, int c2, float t);

// draw.c
int		ft_get_steps(t_bresenham *b);
void	ft_bresenham_step(t_bresenham *b, t_point *p);
void	ft_draw_line(t_map *map, t_point p1, t_point p2);
void	ft_draw_neighbors(t_map *map, int x, int y);
void	ft_draw_map(t_map *map);

// draw_utils.c
void	ft_init_bresenham(t_bresenham *b, t_point p1, t_point p2);
void	ft_compute_scale(t_map *map);
int		ft_count_width(char *line);

// bounds.c
void	ft_update_bounds(t_map *map, int x, int y);
void	ft_reset_bounds(t_map *map);
void	ft_compute_bounds(t_map *map);
void	ft_update_point_bounds(t_map *map, t_point p);
void	ft_compute_offset(t_map *map);

// hook.c
int		ft_bonus_key_hook(int keycode, t_map *map);
void	ft_free_map(t_map *map);
int		ft_close(t_map *map);
void	ft_handle_rotation(int keycode, t_map *map);
int		ft_key_hook(int keycode, t_map *map);

// fdf_utils_bonus.c
void	ft_init_bonus(t_map *map);
void	ft_redraw(t_map *map);
void	ft_apply_zoom(t_map *map, float factor);
void	ft_apply_translation(t_map *map, int dx, int dy);
void	ft_apply_rotation(t_map *map, char axis, float angle);

// projections_bonus.c
t_point	ft_parallel_proj(t_map *map, t_point p);
t_point	ft_conic_proj(t_map *map, t_point p);
t_point	ft_apply_projection(t_map *map, t_point p);
void	ft_handle_projection(int keycode, t_map *map);
void	ft_handle_zoom_translation(int keycode, t_map *map);

// transformations_bonus.c
t_point	ft_apply_transformations(t_map *map, t_point p);
t_point	ft_rotate_z(t_point p, float angle);
t_point	ft_rotate_y(t_point p, float angle);
t_point	ft_rotate_x(t_point p, float angle);

#endif
