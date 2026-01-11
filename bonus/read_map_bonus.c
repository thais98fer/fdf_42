/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:24:45 by thfernan          #+#    #+#             */
/*   Updated: 2026/01/11 03:50:32 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_get_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Cannot open file");
	line = get_next_line(fd);
	if (!line)
		ft_exit_error("Empty file");
	map->width = ft_count_width(line);
	map->height = 1;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_allocate_points(t_map *map)
{
	int	y;

	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		ft_exit_error("Malloc of points failed");
	y = 0;
	while (y < map->height)
	{
		map->points[y] = malloc(sizeof(t_point) * map->width);
		if (!map->points[y])
			ft_exit_error("Malloc of points[y] failed");
		y++;
	}
}

void	ft_fill_row(t_map *map, char *line, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	if (!split)
		ft_exit_error("Split failed");
	x = 0;
	while (x < map->width)
	{
		map->points[y][x].x = x;
		map->points[y][x].y = y;
		map->points[y][x].z = ft_atoi(split[x]);
		x++;
	}
	ft_free_array(split);
}

void	ft_fill_points(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Cannot open file");
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_fill_row(map, line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_read_map(char *filename, t_map *map)
{
	ft_get_map_size(filename, map);
	ft_allocate_points(map);
	ft_fill_points(filename, map);
}
