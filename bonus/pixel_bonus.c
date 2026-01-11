/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:33:08 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 11:37:08 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= 1920 || y >= 1000)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	ft_get_color(int z)
{
	if (z > 50)
		return (0xFFFFFF);
	if (z > 30)
		return (0xFF6B9D);
	if (z > 20)
		return (0xFF1493);
	if (z > 10)
		return (0x9370DB);
	if (z > 5)
		return (0x66B2FF);
	if (z > 0)
		return (0x00CED1);
	if (z == 0)
		return (0x228B22);
	if (z > -10)
		return (0xFFD700);
	if (z > -20)
		return (0xFF8C00);
	return (0x8B4513);
}

int	ft_interpolate_color(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 >> 16) & 0xFF) + t * (((c2 >> 16) & 0xFF) - ((c1 >> 16) & 0xFF));
	g = ((c1 >> 8) & 0xFF) + t * (((c2 >> 8) & 0xFF) - ((c1 >> 8) & 0xFF));
	b = (c1 & 0xFF) + t * ((c2 & 0xFF) - (c1 & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

t_point	ft_isometric_proj(t_map *map, t_point p)
{
	t_point	screen;

	(void)map;
	screen.x = (p.x - p.y) * cos(ISO_ANGLE);
	screen.y = (p.x + p.y) * sin(ISO_ANGLE) - p.z;
	screen.z = p.z;
	return (screen);
}
