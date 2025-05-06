/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:16:30 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/08 11:16:32 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_wall(t_display *data, int wid, int hei)
{
	char	*file;

	file = "assets/wall.xpm";
	data->text->wall = mlx_xpm_file_to_image(data->mlx, file, &wid, &hei);
	if (!data->text->wall)
	{
		ft_printf("Error: Failed to load wall texture\n");
		return (0);
	}
	return (1);
}

int	load_floor(t_display *data, int wid, int hei)
{
	char	*file;

	file = "assets/floor.xpm";
	data->text->floor = mlx_xpm_file_to_image(data->mlx, file, &wid, &hei);
	if (!data->text->floor)
	{
		ft_printf("Error: Failed to load floor texture\n");
		return (0);
	}
	return (1);
}

int	load_collect(t_display *data, int wid, int hei)
{
	char	*file;

	file = "assets/collect.xpm";
	data->text->collect = mlx_xpm_file_to_image(data->mlx, file, &wid, &hei);
	if (!data->text->collect)
	{
		ft_printf("Error: Failed to load collectible texture\n");
		return (0);
	}
	return (1);
}

int	load_exit(t_display *data, int wid, int hei)
{
	char	*file;

	file = "assets/exit.xpm";
	data->text->exit = mlx_xpm_file_to_image(data->mlx, file, &wid, &hei);
	if (!data->text->exit)
	{
		ft_printf("Error: Failed to load exit texture\n");
		return (0);
	}
	return (1);
}

int	load_player(t_display *data, int wid, int hei)
{
	char	*file;

	file = "assets/player.xpm";
	data->text->player = mlx_xpm_file_to_image(data->mlx, file, &wid, &hei);
	if (!data->text->player)
	{
		ft_printf("Error: Failed to load player texture\n");
		return (0);
	}
	return (1);
}
