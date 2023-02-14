/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:08:17 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/14 14:32:47 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<stdio.h>
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

#endif