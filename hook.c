/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:11:16 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/09 16:11:20 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	ft_key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		ft_close(map);
	return (0);
}
