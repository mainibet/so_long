/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:16:46 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/08 11:16:48 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*gnl_map(int fd)
{
	char	*line;
	char	*new_line;

	line = get_next_line(fd);
	if (line)
		new_line = clean_line(line);
	else
		new_line = NULL;
	return (new_line);
}

static int	fill_grid(t_map *map, char *first_line, int fd)
{
	char	*new_line;
	int		len;
	int		i;

	i = 0;
	new_line = first_line;
	while (new_line)
	{
		len = strlen_int(new_line);
		if (extra_check(map, len, new_line) == 0)
			return (0);
		map->grid[i++] = ft_strdup(new_line);
		free(new_line);
		new_line = gnl_map(fd);
	}
	if (!check_shape(map))
	{
		free_array(map->grid, map->rows);
		return (0);
	}
	return (1);
}

int	valid_map(t_map *map, int fd)
{
	char	*line;
	char	*first_line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	first_line = clean_line(line);
	map->cols = ft_strlen(first_line);
	if (fill_grid(map, first_line, fd) == 0)
		return (0);
	if (!check_minchar(map) || !check_walls(map))
	{
		free_array(map->grid, map->rows);
		return (0);
	}
	init_player(map->data);
	if (check_valid_path (map) != 1)
	{
		ft_printf("Error: there is not a valid path\n");
		free_array(map->grid, map->rows);
		return (0);
	}
	return (1);
}

int	map_memory(t_map *map, char *file_name)
{
	map->rows = count_rows(file_name);
	if (map->rows <= 0)
	{
		ft_printf("Error: file contains no valid rows.\n");
		return (0);
	}
	if (map->rows == 0)
	{
		ft_printf("Error: empty map\n");
		return (0);
	}
	map->grid = (char **)ft_calloc(map->rows + 1, sizeof(char *));
	if (!map->grid)
	{
		ft_printf("Error: memory calloc for map\n");
		return (0);
	}
	return (1);
}

void	ini_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->player_c = 0;
	map->exit = 0;
	map->collect = 0;
}
