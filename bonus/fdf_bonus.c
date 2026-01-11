/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:21 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 11:10:06 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_reset_view(t_map *map)
{
	map->zoom = 1.0;
	map->rotate_x = 0;
	map->rotate_y = 0;
	map->rotate_z = 0;
	map->translate_x = 0;
	map->translate_y = 0;
	map->projection = ISOMETRIC;
}

void	ft_init(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.mlx, 1920, 1000, "fdf");
	map->img.img = mlx_new_image(map->mlx.mlx, 1920, 1000);
	map->img.addr = mlx_get_data_addr(map->img.img,
			&map->img.bpp, &map->img.line_len, &map->img.endian);
	mlx_key_hook(map->mlx.window, ft_bonus_key_hook, map);
	mlx_hook(map->mlx.window, 17, 0, ft_close, map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("usage: ./fdf map_filename\n");
		return (1);
	}
	ft_bzero(&map, sizeof(t_map));
	ft_read_map(argv[1], &map);
	ft_init_bonus(&map);
	ft_compute_scale(&map);
	ft_compute_bounds(&map);
	ft_compute_offset(&map);
	ft_init(&map);
	ft_draw_map(&map);
	mlx_key_hook(map.mlx.window, ft_bonus_key_hook, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
