/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:31:24 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/03 14:56:32 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_image(t_display *data)
{
	int		wid;
	int		hei;

	wid = TILE_SIZE;
	hei = TILE_SIZE;
	data->text = malloc(sizeof(t_texture));
	if (!data->text)
		malloc_error();
	load_wall(data, wid, hei);
	load_floor(data, wid, hei);
	load_exit(data, wid, hei);
	load_collect(data, wid, hei);
	load_player(data, wid, hei);
	if (!load_wall(data, wid, hei) || !load_collect(data, wid, hei)
		|| !load_floor(data, wid, hei) || !load_exit(data, wid, hei)
		|| !load_player(data, wid, hei))
		ft_printf("Error loading textures\n");
}

static int	load_map(char *file_name, t_map *map)
{
	int		fd;

	ini_map(map);
	if (!map_memory(map, file_name))
		return (0);
	fd = open_fd(file_name);
	if (fd < 0)
		return (0);
	if (valid_map(map, fd) == 0)
	{
		close_fd(fd);
		return (0);
	}
	close_fd(fd);
	return (1);
}

static void	launch(t_display *data, char *argv)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error: Unable to initialize mlx\n");
		return ;
	}
	ini_data(data);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		malloc_error();
		return ;
	}
	data->map->data = data;
	if (load_map(argv, data->map) == 0)
	{
		ft_printf("Not possible to load map\n");
		exit(1);
	}
	data->win_w = data->map->cols * TILE_SIZE;
	data->win_h = data->map->rows * TILE_SIZE;
}

static int	map_extension(const char *filename)
{
	char	*dot;
	size_t	len;
	size_t	remain;

	if (!filename)
		return (0);
	dot = strrchr(filename, '.');
	if (!dot)
		return (0);
	len = ft_strlen(".ber");
	remain = ft_strlen(dot);
	if (remain == len && strncmp(dot, ".ber", len) == 0)
		return (1);
	else
	{
		ft_printf("Error: Invalid file extension. Expected .ber\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_display	data;
	char		*map_file;

	map_file = argv[1];
	if (argc != 2)
	{
		ft_printf("choose 1 file to begin\n");
		return (1);
	}
	if (!map_extension(map_file))
		return (1);
	launch(&data, argv[1]);
	load_image(&data);
	data.win = create_win(&data);
	if (data.win == NULL)
		return (1);
	render_scene(&data);
	mlx_hook(data.win, 17, 0, close_winx, &data);
	mlx_key_hook(data.win, key_handle, &data);
	mlx_loop(data.mlx);
}
