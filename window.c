/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:59:11 by albetanc          #+#    #+#             */
/*   Updated: 2025/05/01 13:59:13 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_textures(t_display *data)
{
	if (data->text)
	{
		if (data->text->wall)
			mlx_destroy_image(data->mlx, data->text->wall);
		if (data->text->floor)
			mlx_destroy_image(data->mlx, data->text->floor);
		if (data->text->collect)
			mlx_destroy_image(data->mlx, data->text->collect);
		if (data->text->exit)
			mlx_destroy_image(data->mlx, data->text->exit);
		if (data->text->player)
			mlx_destroy_image(data->mlx, data->text->player);
		free(data->text);
	}
}

void	clean_exit(t_display *data, int status)
{
	if (data->map && data->map->grid)
		free_array(data->map->grid, data->map->rows);
	clean_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free(data->map);
	exit(status);
}

int	close_winx(t_display *data)
{
	clean_exit(data, 0);
	return (0);
}

void	*create_win(t_display *data)
{
	char	*msg;

	msg = "Milan The Carrot Hunter";
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, msg);
	if (data->win == NULL)
	{
		ft_printf("Error: creating a window");
		return (NULL);
	}
	return (data->win);
}

void	ini_data(t_display *data)
{
	data->win_h = WIN_HEIGHT;
	data->win_w = WIN_WIDTH;
	data->move_count = 0;
}
