/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:46:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 11:44:55 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_get_steps(t_bresenham *b)
{
	int	steps;

	steps = b->dy;
	if (b->dx > b->dy)
		steps = b->dx;
	if (steps == 0)
		steps = 1;
	return (steps);
}

void	ft_bresenham_step(t_bresenham *b, t_point *p)
{
	b->double_error = 2 * b->error;
	if (b->double_error >= -b->dy)
	{
		b->error -= b->dy;
		p->x += b->step_x;
	}
	if (b->double_error <= b->dx)
	{
		b->error += b->dx;
		p->y += b->step_y;
	}
}

void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	t_bresenham	b;
	int			steps;
	int			i;
	int			color;

	ft_init_bresenham(&b, p1, p2);
	steps = ft_get_steps(&b);
	i = 0;
	while (1)
	{
		color = ft_interpolate_color(ft_get_color(p1.z),
				ft_get_color(p2.z), (float)i / steps);
		ft_put_pixel(&map->img, p1.x, p1.y, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		ft_bresenham_step(&b, &p1);
		i++;
	}
}

void	ft_draw_neighbors(t_map *map, int x, int y)
{
	t_point	current_p;
	t_point	next_p;
	t_point	current_transformed;
	t_point	next_transformed;

	current_p = map->points[y][x];
	current_transformed = ft_apply_transformations(map, current_p);
	if (x < map->width - 1)
	{
		next_p = map->points[y][x + 1];
		next_transformed = ft_apply_transformations(map, next_p);
		current_transformed.z = current_p.z;
		next_transformed.z = next_p.z;
		ft_draw_line(map, current_transformed, next_transformed);
	}
	if (y < map->height - 1)
	{
		next_p = map->points[y + 1][x];
		next_transformed = ft_apply_transformations(map, next_p);
		current_transformed.z = current_p.z;
		next_transformed.z = next_p.z;
		ft_draw_line(map, current_transformed, next_transformed);
	}
}

void	ft_draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_draw_neighbors(map, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx.mlx,
		map->mlx.window, map->img.img, 0, 0);
}
