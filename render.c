/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:50:20 by albetanc          #+#    #+#             */
/*   Updated: 2025/05/01 13:50:22 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_images(t_display *data, int j, int i)
{
	if (data->map->grid[j][i] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->text->wall,
			i * TILE_SIZE, j * TILE_SIZE);
	else if (data->map->grid[j][i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->text->collect, i * TILE_SIZE, j * TILE_SIZE);
	else if (data->map->grid[j][i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->text->exit,
			i * TILE_SIZE, j * TILE_SIZE);
	else if (data->map->grid[j][i] == '0'
		|| data->map->grid[j][i] == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, data->text->floor, i * TILE_SIZE, j * TILE_SIZE);
	else if (data->map->grid[j][i] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->text->player,
			i * TILE_SIZE, j * TILE_SIZE);
}

int	render_scene(void *param)
{
	t_display	*data;
	int			i;
	int			j;

	data = (t_display *)param;
	j = 0;
	while (j < data->map->rows)
	{
		i = 0;
		while (i < data->map->cols)
		{
			put_images(data, j, i);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->text->player,
		data->x * TILE_SIZE, data->y * TILE_SIZE);
	return (0);
}

int	end_game(t_display *data)
{
	ft_printf("Move count: %d\n", data->move_count);
	ft_printf("Mission complete! Every carrot crunched!\n");
	clean_exit(data, 0);
	return (0);
}

int	key_handle(int keycode, void *param)
{
	t_display	*data;
	t_map		*map;

	data = (t_display *)param;
	map = data->map;
	if (keycode == 65361 || keycode == 'a')
		move_left(data);
	else if (keycode == 65363 || keycode == 'd')
		move_right(data);
	else if (keycode == 65362 || keycode == 'w')
		move_up(data);
	else if (keycode == 65364 || keycode == 's')
		move_down(data);
	if (keycode == 65307)
		close_esc(data);
	ft_printf("Move count: %d\n", data->move_count);
	mlx_clear_window(data->mlx, data->win);
	render_scene(data);
	return (0);
}
