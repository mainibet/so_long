/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:50:38 by albetanc          #+#    #+#             */
/*   Updated: 2025/05/01 16:50:42 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_int(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	check_walls(t_map *map)
{
	if (check_first_last_row(map) == 0)
		return (0);
	if (check_cols(map) == 0)
		return (0);
	return (1);
}

int	count_rows(char *file_name)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open_fd(file_name);
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close_fd(fd);
	return (count);
}

char	*clean_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	extra_check(t_map *map, int len, char *new_line)
{
	if (len != map->cols)
	{
		ft_printf("Error: line %d is not the same size\n", map->rows + 1);
		free(new_line);
		free_array(map->grid, map->rows);
		return (0);
	}
	if (check_elem(map, new_line, map->rows) == 0)
	{
		free_array(map->grid, map->rows);
		return (0);
	}
	return (1);
}
