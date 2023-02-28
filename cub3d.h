/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/27 18:50:21 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include"./include/libft/libft.h"
# include<fcntl.h>
# include<math.h>
# include<mlx.h>
# define WIN_WIDTH	500
# define WIN_HEIGHT	500
# define PI	3.14159265
# define VISION 75
# define FOWARD		13
# define BACKWARD	1
# define LEFT	0
# define RIGHT	2

# define CHR_SET "01NSEW"

typedef struct s_map{
	char		**raw_map;
	char		**map;

	int			y_max;
	int			flag;
	int			player_y;
	int			player_x;
	int			fd;

	int			*color_floor;
	int			*color_ceil;
	int			hex_color_floor;
	int			hex_color_ceil;
	char		*wall_no;
	char		*wall_so;
	char		*wall_ea;
	char		*wall_we;

	char		p_orientation;
}	t_map;

typedef struct s_img{
	void		*pointer;
	int			height;
	int			width;
	int			bpp;
	int			size_line;
	int			endian;
	char		*screen_data;
}	t_img;

typedef struct s_ray{
	int			position;
	double		x;
	double		y;
	double		cos;
	double		sin;
	double		angle;
	double		distance;
	int			wall_h;
}	t_ray;

typedef struct s_data{
	void		*mlx;
	void		*window;
	t_map		*map;
	double		player_x;
	double		player_y;
	double		dir_x;
	char		*screen_data;
	t_img		img;
	t_img		text_n;
	t_img		text_s;
	t_img		text_e;
	t_img		text_w;
}	t_data;

//Parsing
int		parsing(t_map *map, char *argv);
char	*format_string(char *str);
int		*split_rgb(char *str);
int		parse_line(char *str);
int		check_file_format(char *str);
int		check_img_file(char *str);
int		check_texture_files(t_map *map);
int		copy_map(t_map *map);
int		check_frst_lines(t_map *map);
int		check_valid_map(t_map *map);
int		parse_colors(t_map *map);
int		find_player(t_map *map);
int		check_components(t_map *map);
int		get_map_data(t_map *map);
int		open_map(t_map *map, char *argv);

//Errors and exit
int		print_error(t_map *map, char *str);
int		clear_structs(t_map *map, int exit_code);

// raycasting
void	raycasting(t_data *data);

//mouvements
int	player_move(int keycode, t_data *data);
void	print_window(t_data *data);

//utils
int		in_char_set(char c, char *char_set);

// raycasting
void	raycasting(t_data *data);

//mouvements
int		player_move(int keycode, t_data *data);
void	print_window(t_data *data);

#endif
