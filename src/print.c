/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:25:25 by slord             #+#    #+#             */
/*   Updated: 2023/03/08 14:52:55 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	aquarium(t_data *data)
{
	if (data->fish_eye == 0)
		data->fish_eye = 1;
	else
		data->fish_eye = 0;
	return (0);
}

int	fish_eye(t_data *data)
{
	if (data->aqua == 0)
		data->aqua = 1;
	else
		data->aqua = 0;
	print_window(data);
	return (0);
}

void	draw_floor(t_data *data)
{
	int	x;
	int	array_length;

	array_length = WIN_WIDTH * WIN_HEIGHT;
	x = 0;
	while (x < array_length)
	{
		if (x < array_length / 2)
		{
			data->img.screen_data[x * 4] = data->map->color_ceil[2];
			data->img.screen_data[x * 4 + 1] = data->map->color_ceil[1];
			data->img.screen_data[x * 4 + 2] = data->map->color_ceil[0];
		}
		else
		{
			data->img.screen_data[x * 4] = data->map->color_floor[2];
			data->img.screen_data[x * 4 + 1] = data->map->color_floor[1];
			data->img.screen_data[x * 4 + 2] = data->map->color_floor[0];
		}
		x++;
	}
}

void	print_window(t_data *data)
{
	if (data->img.pointer)
		(data->img.pointer = NULL);
	if (data->window)
		mlx_clear_window(data->mlx, data->window);
	data->img.pointer = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.screen_data = mlx_get_data_addr(data->img.pointer,
			&data->img.bpp, &data->img.size_line, &data->img.endian);
	draw_floor(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.pointer, 0, 0);
	mlx_destroy_image(data->mlx, data->img.pointer);
}
