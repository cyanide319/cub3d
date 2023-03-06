/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/06 16:18:13 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	game_over(t_data *data, int exit_code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (exit_code != 0)
	{
		mlx_destroy_image(data->mlx, data->text_e.pointer);
		mlx_destroy_image(data->mlx, data->text_w.pointer);
		mlx_destroy_image(data->mlx, data->text_n.pointer);
		mlx_destroy_image(data->mlx, data->text_s.pointer);		
	}
	exit(exit_code);
}

void init_data(t_data *data, t_map *map)
{ 
	
	data->player_x = map->player_x;
	data->player_y = map->player_y;
	printf("playerx = %d \n playery = %d \n player_orienta = %d", map->player_x, map->player_y, map->p_orientation);
	printf("playerdtatx = %f \n playdsadery = %f \n player_orienta = %d", data->player_x, data->player_y, map->p_orientation);
	data->dir_x = 0;
}
void	free_struct (t_data *data)
{
	
	free(data->map);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_data 			data;

	map = ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
	{
		if (parsing(map, argv[1]) < 0)
			return (-1);
	}
	else
		return (print_error(map, "Argument: maps/map"));

	data.map = map;
	init_data(&data, map);
	data.mlx = mlx_init();
	img_init(&data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	player_move(777, &data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_hook(data.window, 17, 0, game_over, &data);
	mlx_loop(data.mlx);
}
 