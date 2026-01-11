/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 04:01:51 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 11:53:55 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	ft_rotate_x(t_point p, float angle)
{
	t_point	rotated;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rotated.x = p.x;
	rotated.y = p.y * cos_a - p.z * sin_a;
	rotated.z = p.y * sin_a + p.z * cos_a;
	return (rotated);
}

t_point	ft_rotate_y(t_point p, float angle)
{
	t_point	rotated;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rotated.x = p.x * cos_a + p.z * sin_a;
	rotated.y = p.y;
	rotated.z = -p.x * sin_a + p.z * cos_a;
	return (rotated);
}

t_point	ft_rotate_z(t_point p, float angle)
{
	t_point	rotated;
	double	cos_a;
	double	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rotated.x = p.x * cos_a - p.y * sin_a;
	rotated.y = p.x * sin_a + p.y * cos_a;
	rotated.z = p.z;
	return (rotated);
}

t_point	ft_apply_transformations(t_map *map, t_point p)
{
	t_point	transformed;
	float	center_x;
	float	center_y;

	transformed.x = p.x * map->scale;
	transformed.y = p.y * map->scale;
	transformed.z = p.z * map->z_scale;
	center_x = (map->width / 2.0) * map->scale;
	center_y = (map->height / 2.0) * map->scale;
	transformed.x -= center_x;
	transformed.y -= center_y;
	if (map->rotate_x != 0)
		transformed = ft_rotate_x(transformed, map->rotate_x);
	if (map->rotate_y != 0)
		transformed = ft_rotate_y(transformed, map->rotate_y);
	if (map->rotate_z != 0)
		transformed = ft_rotate_z(transformed, map->rotate_z);
	transformed = ft_apply_projection(map, transformed);
	transformed.x *= map->zoom;
	transformed.y *= map->zoom;
	transformed.x += map->offset_x + map->translate_x;
	transformed.y += map->offset_y + map->translate_y;
	return (transformed);
}
