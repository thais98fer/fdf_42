/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 04:01:03 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 11:43:51 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point	ft_parallel_proj(t_map *map, t_point p)
{
	t_point	screen;

	(void)map;
	screen.x = p.x;
	screen.y = p.y - p.z;
	screen.z = p.z;
	return (screen);
}

t_point	ft_apply_projection(t_map *map, t_point p)
{
	if (map->projection == PARALLEL)
		return (ft_parallel_proj(map, p));
	return (ft_isometric_proj(map, p));
}

void	ft_handle_projection(int keycode, t_map *map)
{
	if (keycode == KEY_I)
		map->projection = ISOMETRIC;
	else if (keycode == KEY_P)
		map->projection = PARALLEL;
}

void	ft_handle_zoom_translation(int keycode, t_map *map)
{
	if (keycode == KEY_PLUS)
		ft_apply_zoom(map, 1.1);
	else if (keycode == KEY_MINUS)
		ft_apply_zoom(map, 0.9);
	else if (keycode == KEY_W)
		ft_apply_translation(map, 0, -20);
	else if (keycode == KEY_S)
		ft_apply_translation(map, 0, 20);
	else if (keycode == KEY_A)
		ft_apply_translation(map, -20, 0);
	else if (keycode == KEY_D)
		ft_apply_translation(map, 20, 0);
}
