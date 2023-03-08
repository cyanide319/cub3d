/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:27 by slord             #+#    #+#             */
/*   Updated: 2023/03/08 14:45:28 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	move_foward(t_data *data)
{
	double	temp_y;
	double	temp_x;

	temp_y = MOVE_LENGTH * sin (data->dir_x * (PI / 180));
	temp_x = MOVE_LENGTH * cos ((data->dir_x * (PI / 180)));
	data->player_y += temp_y;
	data->player_x += temp_x;
}

void	move_backward(t_data *data)
{
	double	temp_y;
	double	temp_x;

	temp_y = MOVE_LENGTH * sin(data->dir_x * (PI / 180));
	temp_x = MOVE_LENGTH * cos((data->dir_x * (PI / 180)));
	data->player_y -= temp_y;
	data->player_x -= temp_x;
}

void	move_right(t_data *data)
{
	double	temp_y;
	double	temp_x;

	temp_x = MOVE_LENGTH * cos((data->dir_x - 90) * (PI / 180));
	temp_y = MOVE_LENGTH * sin((data->dir_x - 90) * (PI / 180));
	data->player_y -= temp_y;
	data->player_x -= temp_x;
}

void	move_left(t_data *data)
{
	double	temp_y;
	double	temp_x;

	temp_x = MOVE_LENGTH * cos((data->dir_x + 90) * (PI / 180));
	temp_y = MOVE_LENGTH * sin((data->dir_x + 90) * (PI / 180));
	data->player_y -= temp_y;
	data->player_x -= temp_x;
}

void	check_move(int keycode, t_data *data)
{
	double	x;
	double	y;

	x = data->player_x;
	y = data->player_y;
	if (keycode == FOWARD)
		move_foward(data);
	else if (keycode == BACKWARD)
		move_backward(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == LEFT)
		move_left(data);
	if (!data->map->map[(int)floor(data->player_y)][(int)floor(data->player_x)]
			|| data->map->map[(int)floor(data->player_y)]
			[(int)floor(data->player_x)] == ' '
			|| data->map->map[(int)floor(data->player_y)]
			[(int)floor(data->player_x)] == '1')
	{
		data->player_x = x;
		data->player_y = y;
	}
}
