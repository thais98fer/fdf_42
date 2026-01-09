/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:33:08 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/09 17:48:31 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= 1200 || y >= 800)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	ft_get_color(int z)
{
	if (z > 0)
		return (0x66B2FF);
	return (0xFFFFFF);
}

t_point	ft_isometric_proj(t_point p)
{
	t_point	screen;
	double	x;
	double	y;

	x = p.x * SCALE;
	y = p.y * SCALE;
	screen.x = (x - y) * cos(ISO_ANGLE);
	screen.y = (x + y) * sin(ISO_ANGLE) - (p.z * SCALE);
	screen.x += 1200 / 2;
	screen.y += 800 / 2;
	screen.z = p.z;
	return (screen);
}
