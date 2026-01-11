/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:11:16 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 04:32:12 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_free_map(t_map *map)
{
	int	y;

	if (!map || !map->points)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->points[y]);
		y++;
	}
	free(map->points);
	map->points = NULL;
}

int	ft_close(t_map *map)
{
	if (!map)
		exit(0);
	ft_free_map(map);
	if (map->img.img)
		mlx_destroy_image(map->mlx.mlx, map->img.img);
	if (map->mlx.window)
		mlx_destroy_window(map->mlx.mlx, map->mlx.window);
	if (map->mlx.mlx)
	{
		mlx_destroy_display(map->mlx.mlx);
		free(map->mlx.mlx);
	}
	exit(0);
	return (0);
}

void	ft_handle_rotation(int keycode, t_map *map)
{
	if (keycode == KEY_Q)
		ft_apply_rotation(map, 'x', 0.1);
	else if (keycode == KEY_E)
		ft_apply_rotation(map, 'x', -0.1);
	else if (keycode == KEY_Z)
		ft_apply_rotation(map, 'y', 0.1);
	else if (keycode == KEY_X)
		ft_apply_rotation(map, 'y', -0.1);
	else if (keycode == KEY_C)
		ft_apply_rotation(map, 'z', 0.1);
	else if (keycode == KEY_V)
		ft_apply_rotation(map, 'z', -0.1);
}

int	ft_bonus_key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
	{
		ft_close(map);
		return (0);
	}
	if (keycode == KEY_SPACE)
		ft_reset_view(map);
	ft_handle_zoom_translation(keycode, map);
	ft_handle_projection(keycode, map);
	ft_handle_rotation(keycode, map);
	ft_redraw(map);
	return (0);
}
