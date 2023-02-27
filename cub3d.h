/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/27 13:47:02 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include"./include/libft/libft.h"
# include"MLX42/include/MLX42/MLX42.h"
# include<fcntl.h>
// # include<>
// # include<>
// # include<>
// # include<>

# define CHR_SET "01NSEW"

typedef struct s_map{
	char		**raw_map;
	char		**map;

	int			y_max;
	int			flag;

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

typedef struct s_game{
	t_map	*map;
	int		fd;
	void	*img;
	void	*mlx_win;
	void	*mlx;
	void	*xpm;
}	t_game;

//Parsing
int		parsing(t_game *game, t_map *map, char *argv);
char	*format_string(char *str);
int		*split_rgb(char *str);
int		parse_line(char *str);
int		check_img_file(char *str);
int		check_texture_files(t_map *map);
int		copy_map(t_map *map);
int		check_frst_lines(t_map *map);
int		check_valid_map(t_map *map);
int		parse_colors(t_map *map);
int		find_player(t_map *map);
int		check_components(t_map *map);

//Errors and exit
int		print_error(t_game *game, t_map *map, char *str);
int		clear_structs(t_game *game, t_map *map, int exit_code);

//utils
int		in_char_set(char c, char *char_set);

#endif
