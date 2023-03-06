/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:25:25 by slord             #+#    #+#             */
/*   Updated: 2023/03/06 14:09:32 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	draw_floor(t_data *data)
{
	int	x;
	int	array_length;

	array_length = WIN_WIDTH * WIN_HEIGHT;
	x = 0;
	while (x < array_length)
	{
		if (x < array_length / 2)
			data->img.screen_data[x * 4] = 100;
		else
			data->img.screen_data[x * 4 + 1] = 100;
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