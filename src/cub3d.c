/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:06:27 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/28 13:14:03 by tbeaudoi         ###   ########.fr       */
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
{ /*
	char *test1 = "11111111111111";
	char *test2 = "11000010000011111111111111111111111111111111111111111111111111111111111111111";
	char *test3 = "1100000000000000000000000000000000000000000000000000000000000000111";
	char *test4 = "110010000000111111111111111111111110000000000000000000000011111111";
	char *test5 = "11111111111111111111111111111111111111111111111111111111111111";

	data->map = malloc(sizeof(char *) * 6);

	
	
			data->map[0]= ft_strdup(test1);
			data->map[1]= ft_strdup(test2);
			data->map[2]= ft_strdup(test3);
			data->map[3]= ft_strdup(test4);
			data->map[4]= ft_strdup(test5);
	

	*/
	data->dir_x =180;
	//data->dir_y = -1;
	data->player_x = 18.0;
	data->player_y = 3.0;
	img_init(data);
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
	//init_textures(data);
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	//screen(data.screen_data, size_line);
	print_window(&data);
	mlx_hook(data.window, 2, 0, player_move, &data);
	mlx_loop(data.mlx);
}
 