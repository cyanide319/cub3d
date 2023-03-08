/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 14:54:11 by slord            ###   ########.fr       */
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
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	clear_structs(data, 0);
	exit(exit_code);
}

void init_data(t_data *data, t_map *map)
{ 

	data->player_x = map->player_x + MOVE_LENGTH + 0.1;
	data->player_y = map->player_y + MOVE_LENGTH + 0.1;
	data->fish_eye = 0;
	data->aqua = 0;
	if (map->p_orientation == 'N')
		data->dir_x = 270;
	else if (map->p_orientation == 'E')
		data->dir_x = 0;
	else if (map->p_orientation == 'S')
		data->dir_x = 90;
	else
		data->dir_x = 180;
}
void	free_struct (t_data *data)
{
	
	free(data->map);
}

int	main(int argc, char **argv)
{
	t_data 			data;

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
		return (print_error(&data, "Bad texture file"));
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	player_move(777, &data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_hook(data.window, 17, 0, game_over, &data);
	mlx_loop(data.mlx);
	return (0);
}
 