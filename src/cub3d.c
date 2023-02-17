/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/16 19:07:17 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			*map;
	t_game			*game;

	game = ft_calloc(sizeof(t_game), 1);
	map = ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
	{
		if (parsing(game, map, argv[1]) < 0)
			return (-1);
	}
	else
		return (print_error(game, map, "Argument: maps/map"));
	mlx = mlx_init(1000, 1000, "cub3d", false);
	img = mlx_new_image(mlx, 256, 256);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
