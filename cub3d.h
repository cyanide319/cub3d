/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/16 11:57:18 by tbeaudoi         ###   ########.fr       */
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
	char	**map;
	int		y;
	int		x;
	int		img_x;
	int		img_y;
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
int		parsing(char *argv);

//Errors
int		print_error(char *str);
int		print_error_n_free(char *str, void *ptr);

//utils
t_game	*get_t_game(void);
t_map	*get_t_map(void);
int		free_ptr(void **ptr);
void	*free_tab(char ***ptab);
void	*ft_realloc_tab(char **ptr, size_t size);

#endif
