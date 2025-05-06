/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:34:59 by albetanc          #+#    #+#             */
/*   Updated: 2025/05/01 13:35:01 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_elem(t_map *map, char *line, int line_n)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '1' && line[i] != '0')
		{
			ft_printf("Error: invalid char %c at line %d\n", line[i], line_n);
			free (line);
			return (0);
		}
		if (line[i] == 'P')
			map->player_c++;
		if (line[i] == 'E')
			map->exit++;
		if (line[i] == 'C')
			map->collect++;
		i++;
	}
	return (1);
}

int	check_minchar(t_map *map)
{
	if (map->player_c != 1 || map->exit != 1 || map->collect < 1)
	{
		if (map->player_c != 1)
			ft_printf("Error: should be only 1 player\n");
		if (map->exit != 1)
			ft_printf("Error: should be only 1 exit\n");
		if (map->collect < 1)
			ft_printf("Error: should be at least 1 collectible\n");
		return (0);
	}
	return (1);
}

int	check_shape(t_map *map)
{
	map->max_cols = map->data->win_w / TILE_SIZE;
	map->max_rows = map->data->win_h / TILE_SIZE;
	if (map->rows < 2 || map->cols < 2)
	{
		ft_printf("Error: map not big enough\n");
		return (0);
	}
	if (map->rows > map->max_rows || map->cols > map->max_cols)
	{
		ft_printf("Map to big, won't fit in the window\n");
		return (0);
	}
	return (1);
}

int	check_cols(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->rows -1)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->cols - 1] != '1')
		{
			ft_printf("Error enclosing walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_first_last_row(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->grid[0][i] != '1')
		{
			ft_printf("Error enclosing walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		if (map->grid[map->rows - 1][i] != '1')
		{
			ft_printf("Error enclosing walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}
