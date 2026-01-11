/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:18:18 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 04:05:04 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_update_bounds(t_map *map, int x, int y)
{
	if (x < map->min_x)
		map->min_x = x;
	if (x > map->max_x)
		map->max_x = x;
	if (y < map->min_y)
		map->min_y = y;
	if (y > map->max_y)
		map->max_y = y;
}

void	ft_reset_bounds(t_map *map)
{
	map->min_x = 2147483647;
	map->min_y = 2147483647;
	map->max_x = -2147483648;
	map->max_y = -2147483648;
}

void	ft_compute_offset(t_map *map)
{
	map->offset_x = (WIN_W - (map->max_x - map->min_x)) / 2 - map->min_x;
	map->offset_y = (WIN_H - (map->max_y - map->min_y)) / 2 - map->min_y;
}

void	ft_update_point_bounds(t_map *map, t_point p)
{
	t_point	proj;

	proj = ft_apply_transformations(map, p);
	ft_update_bounds(map, proj.x, proj.y);
}

void	ft_compute_bounds(t_map *map)
{
	int	x;
	int	y;

	ft_reset_bounds(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_update_point_bounds(map, map->points[y][x]);
			if (x < map->width - 1)
				ft_update_point_bounds(map, map->points[y][x + 1]);
			if (y < map->height - 1)
				ft_update_point_bounds(map, map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
