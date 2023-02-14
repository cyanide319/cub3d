/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/14 16:19:12 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
# include"./include/libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
// #include<>
// #include<>
// #include<>
// #include<>

typedef struct s_map{
	char	**map;
	int		y;
	int		x;
	int		img_x;
	int		img_y;
	int		fd;

	void	*img;
	void	*mlx_win;
	void	*mlx;
	void	*xpm;
}	t_map;

//Parsing
int	parsing(char *argv);

//Errors
int	print_error(char *str, int error);

#endif
