/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albetanc <albetanc@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:31:51 by albetanc          #+#    #+#             */
/*   Updated: 2025/04/03 11:49:07 by albetanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define TILE_SIZE 32

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map	t_map;

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_texture;

typedef struct s_display
{
	int			ini_xplayer;
	int			ini_yplayer;
	int			x;
	int			y;
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			move_count;
	t_map		*map;
	t_texture	*text;
}	t_display;

typedef struct s_map
{
	char		**grid;
	int			rows;
	int			cols;
	int			max_rows;
	int			max_cols;
	int			player_c;
	int			exit;
	int			collect;
	t_display	*data;
}	t_map;

int		close_winx(t_display *data);
void	*create_win(t_display *data);
void	ini_data(t_display *data);
int		check_elem(t_map *map, char *line, int line_n);
int		check_minchar(t_map *map);
int		check_shape(t_map *map);
int		check_cols(t_map *map);
int		check_first_last_row(t_map *map);
int		check_walls(t_map *map);
int		count_rows(char *file_name);
char	*clean_line(char *line);
int		strlen_int(char *str);
int		valid_map(t_map *map, int fd);
int		map_memory(t_map *map, char *file_name);
void	ini_map(t_map *map);
int		extra_check(t_map *map, int len, char *new_line);
int		load_wall(t_display *data, int wid, int hei);
int		load_floor(t_display *data, int wid, int hei);
int		load_collect(t_display *data, int wid, int hei);
int		load_exit(t_display *data, int wid, int hei);
int		load_player(t_display *data, int wid, int hei);
int		strlen_int(char *str);
int		check_valid_path(t_map *map);
int		render_scene(void *param);
int		end_game(t_display *data);
int		key_handle(int keycode, void *param);
void	init_player(t_display *data);
void	move_left(t_display *data);
void	move_right(t_display *data);
void	move_up(t_display *data);
void	move_down(t_display *data);
void	close_esc(t_display *data);
int		end_game(t_display *data);
void	clean_exit(t_display *data, int status);

#endif
