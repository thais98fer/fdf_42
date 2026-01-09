/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:53:21 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/09 17:43:58 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.mlx, 1200, 800, "fdf");
	map->img.img = mlx_new_image(map->mlx.mlx, 1200, 800);
	map->img.addr = mlx_get_data_addr(map->img.img,
			&map->img.bpp, &map->img.line_len, &map->img.endian);
	mlx_key_hook(map->mlx.window, ft_key_hook, map);
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
	ft_read_map(argv[1], &map);
	ft_init(&map);
	ft_draw_map(&map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
