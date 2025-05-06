/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:20:02 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/28 10:21:57 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		malloc_error();
	i = 0;
	while (i < map->rows)
	{
		copy[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!copy[i])
		{
			free_array(copy, i);
			malloc_error();
		}
		ft_strlcpy(copy[i], map->grid[i], map->cols + 1);
		i++;
	}
	return (copy);
}

void	init_player(t_display *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map->rows)
	{
		i = 0;
		while (i < data->map->cols)
		{
			if (data->map->grid[j][i] == 'P')
			{
				data->ini_xplayer = i;
				data->ini_yplayer = j;
				data->x = data->ini_xplayer;
				data->y = data->ini_yplayer;
				return ;
			}
			i++;
		}
		j++;
	}
	ft_printf("Error: Player position ('P') not found in the map\n");
}

static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows)
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'x')
		return ;
	map->grid[y][x] = 'x';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	exit_reach(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->grid[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_path(t_map *map)
{
	char	**copy;
	t_map	tmp_map;

	copy = copy_map(map);
	if (!copy)
		malloc_error();
	tmp_map.grid = copy;
	tmp_map.rows = map->rows;
	tmp_map.cols = map->cols;
	flood_fill(&tmp_map, map->data->ini_xplayer, map->data->ini_yplayer);
	if (!exit_reach(&tmp_map))
	{
		free_array(copy, map->rows);
		return (0);
	}
	free_array(copy, map->rows);
	return (1);
}
