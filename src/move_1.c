/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:27 by slord             #+#    #+#             */
/*   Updated: 2023/03/06 15:30:15 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	player_move(int keycode, t_data *data)
{
	if (keycode == 53)
		game_over(data, 0);
	if (keycode != 777)
		check_move(keycode, data);
	if (keycode == 123)
		data->dir_x -= 5;
	else if (keycode == 124)
		data->dir_x += 5;
	if (data->dir_x > 360)
		data->dir_x = 5;
	else if (data->dir_x < 0)
		data->dir_x = 360 - 5;
	print_window(data);
	return (0);
}
