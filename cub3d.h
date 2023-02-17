/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/17 18:10:47 by tbeaudoi         ###   ########.fr       */
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

typedef struct s_map{
	char	**raw_map;
	char	**map;
	int		flag;
	int		*color_floor;
	int		*color_ceil;
	char	*wall_no;
	char	*wall_so;
	char	*wall_ea;
	char	*wall_we;
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

//Errors and exit
int		print_error(t_game *game, t_map *map, char *str);
int		clear_structs(t_game *game, t_map *map, int exit_code);

//utils
// int		free_ptr(void **ptr);
// void	*free_tab(char ***ptab);
// void	*ft_realloc_tab(char **ptr, size_t size);

#endif
