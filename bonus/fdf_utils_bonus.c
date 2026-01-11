/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 04:00:05 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 04:16:34 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_init_bonus(t_map *map)
{
	map->projection = ISOMETRIC;
	map->zoom = 1.0;
	map->rotate_x = 0;
	map->rotate_y = 0;
	map->rotate_z = 0;
	map->translate_x = 0;
	map->translate_y = 0;
}

void	ft_apply_zoom(t_map *map, float factor)
{
	map->zoom *= factor;
	if (map->zoom < 0.1)
		map->zoom = 0.1;
	if (map->zoom > 10.0)
		map->zoom = 10.0;
}

void	ft_apply_translation(t_map *map, int dx, int dy)
{
	map->translate_x += dx;
	map->translate_y += dy;
}

void	ft_apply_rotation(t_map *map, char axis, float angle)
{
	if (axis == 'x')
		map->rotate_x += angle;
	else if (axis == 'y')
		map->rotate_y += angle;
	else if (axis == 'z')
		map->rotate_z += angle;
}

void	ft_redraw(t_map *map)
{
	mlx_destroy_image(map->mlx.mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx.mlx, WIN_W, WIN_H);
	map->img.addr = mlx_get_data_addr(map->img.img,
			&map->img.bpp, &map->img.line_len, &map->img.endian);
	ft_draw_map(map);
}
