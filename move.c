/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:32:09 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/30 11:32:12 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_display *data)
{
	if (data->x > 0 && data->map->grid[data->y][data->x - 1] != '1')
	{
		if (data->map->grid[data->y][data->x - 1] == 'C')
		{
			data->map->grid[data->y][data->x - 1] = '0';
			data->map->collect--;
		}
		else if (data->map->grid[data->y][data->x - 1] == 'E'
			&& data->map->collect == 0)
		{
			data->x -= 1;
			data->move_count++;
			end_game(data);
			return ;
		}
		data->x -= 1;
		data->move_count++;
	}
}

void	move_right(t_display *data)
{
	if (data->x < data->map->cols - 1
		&& data->map->grid[data->y][data->x + 1] != '1')
	{
		if (data->map->grid[data->y][data->x + 1] == 'C')
		{
			data->map->grid[data->y][data->x + 1] = '0';
			data->map->collect--;
		}
		else if (data->map->grid[data->y][data->x + 1] == 'E'
			&& data->map->collect == 0)
		{
			data->x += 1;
			data->move_count++;
			end_game(data);
			return ;
		}
		data->x += 1;
		data->move_count++;
	}
}

void	move_up(t_display *data)
{
	if (data->y > 0 && data->map->grid[data->y - 1][data->x] != '1')
	{
		if (data->map->grid[data->y - 1][data->x] == 'C')
		{
			data->map->grid[data->y - 1][data->x] = '0';
			data->map->collect--;
		}
		else if (data->map->grid[data->y - 1][data->x] == 'E'
			&& data->map->collect == 0)
		{
			data->y -= 1;
			data->move_count++;
			end_game(data);
			return ;
		}
		data->y -= 1;
		data->move_count++;
	}
}

void	move_down(t_display *data)
{
	if (data->y < data->map->rows - 1
		&& data->map->grid[data->y + 1][data->x] != '1')
	{
		if (data->map->grid[data->y + 1][data->x] == 'C')
		{
			data->map->grid[data->y + 1][data->x] = '0';
			data->map->collect--;
		}
		else if (data->map->grid[data->y + 1][data->x] == 'E'
			&& data->map->collect == 0)
		{
			data->y += 1;
			data->move_count++;
			end_game(data);
			return ;
		}
		data->y += 1;
		data->move_count++;
	}
}

void	close_esc(t_display *data)
{
	clean_exit(data, 0);
	exit(0);
}
