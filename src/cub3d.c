/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:08:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 16:09:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
	{
		if (parsing(&data, argv[1]) < 0)
			return (-1);
	}
	else
		return (print_error(&data, "Argument: maps/map"));
	init_data(&data, data.map);
	data.mlx = mlx_init();
	if (img_init(&data) < 0)
		game_over(&data, -1);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	player_move(777, &data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_hook(data.window, 17, 0, game_over, &data);
	mlx_loop(data.mlx);
	return (0);
}
