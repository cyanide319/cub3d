/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/27 18:38:10 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	data;

	map = ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
	{
		if (parsing(map, argv[1]) < 0)
			return (-1);
	}
	else
		return (print_error(map, "Argument: maps/map"));

	data.map = map;
	init_data(&data);
	data.mlx = mlx_init();
	//init_textures(data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	//screen(data.screen_data, size_line);
	print_window(&data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_loop(data.mlx);
}
