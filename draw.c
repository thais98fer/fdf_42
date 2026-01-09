/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:46:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/09 20:19:27 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	t_bresenham	

	dx = ft_nbr_abs(p2.x - p1.x);
	dy = ft_nbr_abs(p2.y - p1.y);
	step_x = -1;
	step_y = -1;
	if (p1.x < p2.x)
		step_x = 1;
	if (p1.y < p2.y)
		step_y = 1;
	error = dx - dy;
	while (1)
	{
		ft_put_pixel(&map->img, p1.x, p1.y, ft_get_color(p1.z));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		double_error = 2 * error;
		if (double_error > -dy)
		{
			error -= dy;
			p1.x += step_x;
		}
		if (double_error < dx)
		{
			error += dx;
			p1.y += step_y;
		}
	}
}

void	ft_draw_neighbors(t_map *map, int x, int y)
{
	t_point	current_p;
	t_point	next_p;

	current_p = ft_isometric_proj(map->points[y][x]);
	if (x < map->width - 1)
	{
		next_p = ft_isometric_proj(map->points[y][x + 1]);
		ft_draw_line(map, current_p, next_p);
	}
	if (y < map->height - 1)
	{
		next_p = ft_isometric_proj(map->points[y + 1][x]);
		ft_draw_line(map, current_p, next_p);
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
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.window, map->img.img, 0, 0);
}
