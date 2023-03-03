/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/03 14:09:37 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	screen(char *img_data, int line_size)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if (y <  WIN_HEIGHT / 2)
				img_data[x * 4 + 4 * (line_size / 4) * y] = 0x000080;
			else
				img_data[x * 4 + 4 * (line_size / 4) * y + 1] = 100;
			x++;
		}
		x = 0;
		y++;	
	}
}

void init_data(t_data *data)
{ 
	data->dir_x =180;
	//data->dir_y = -1;
	data->player_x = 18.0;
	data->player_y = 3.0;
	// img_init(data);
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
	init_data(&data);
	data.mlx = mlx_init();
	img_init(&data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	//screen(data.screen_data, size_line);
	//print_window(&data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_loop(data.mlx);
}
 