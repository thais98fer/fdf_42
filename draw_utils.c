/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:53:47 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 02:19:13 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_bresenham(t_bresenham *b, t_point p1, t_point p2)
{
	b->dx = ft_nbr_abs(p2.x - p1.x);
	b->dy = ft_nbr_abs(p2.y - p1.y);
	b->step_x = -1;
	b->step_y = -1;
	if (p1.x < p2.x)
		b->step_x = 1;
	if (p1.y < p2.y)
		b->step_y = 1;
	b->error = b->dx - b->dy;
}

void	ft_compute_scale(t_map *map)
{
	int	max_dim;

	max_dim = map->width;
	if (map->height > max_dim)
		max_dim = map->height;
	if (max_dim > 300)
		map->scale = 1;
	else if (max_dim > 200)
		map->scale = 2;
	else if (max_dim > 100)
		map->scale = 5;
	else if (max_dim > 50)
		map->scale = 10;
	else
		map->scale = 30;
	map->z_scale = map->scale / 2;
	if (map->z_scale < 1)
		map->z_scale = 1;
}

int	ft_count_width(char *line)
{
	char	**split;
	int		width;

	split = ft_split(line, ' ');
	if (!split)
		ft_exit_error("Split failed");
	width = 0;
	while (split[width])
		width++;
	ft_free_array(split);
	return (width);
}
