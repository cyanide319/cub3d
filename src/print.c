/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:25:25 by slord             #+#    #+#             */
/*   Updated: 2023/02/27 16:56:24 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	print_window(t_data *data)
{
	if (data->img.pointer)
		mlx_clear_window(data->mlx, data->window);
	//if (data->img.pointer)
		//free(data->img.pointer);
	data->img.pointer = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.screen_data = mlx_get_data_addr(data->img.pointer,
			&data->img.bpp, &data->img.size_line, &data->img.endian);	
	raycasting(data);
}