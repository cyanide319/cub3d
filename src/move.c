/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:35:27 by slord             #+#    #+#             */
/*   Updated: 2023/02/24 21:58:49 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

//int	validate_move(t_data *data)
//{
	
//}
void move_foward(t_data *data)
{
	double temp_y;
	double temp_x;

	temp_y = 0.5 * sin(data->dir_x* (PI / 180));
	temp_x = 0.5 * sin(90 -(data->dir_x* (PI / 180)));
	//data->player_x += cos(data->dir_x * (PI / 180))
	//	/ 10;
	//data->player_y += sin(data->dir_x * (PI / 180))
	//	/ 10;
	data->player_y += temp_y;
	data->player_x += temp_x;
	
}
void move_backward(t_data *data)
{
	double temp_y;
	double temp_x;

	temp_y = 0.5 * sin(data->dir_x* (PI / 180));
	temp_x = 0.5 * sin(90-(data->dir_x* (PI / 180)));
	//data->player_x += cos(data->dir_x * (PI / 180))
	//	/ 10;
	//data->player_y += sin(data->dir_x * (PI / 180))
	//	/ 10;
	data->player_y -= temp_y;
	data->player_x -= temp_x;
	
}

void move_right(t_data *data)
{
	double temp_y;
	double temp_x;
	
	temp_x = 0.5 * cos((data->dir_x - 90)* (PI / 180));
	temp_y = 0.5 * sin((data->dir_x - 90) *(PI / 180));
	//data->player_x += cos(data->dir_x * (PI / 180))
	//	/ 10;
	//data->player_y += sin(data->dir_x * (PI / 180))
	//	/ 10;
	data->player_y -= temp_y;
	data->player_x -= temp_x;
	
}

void move_left(t_data *data)
{
	double temp_y;
	double temp_x;

	temp_x = 0.5 * cos((data->dir_x + 90)* (PI / 180));
	temp_y = 0.5 * sin((data->dir_x + 90) *(PI / 180));
	//data->player_x += cos(data->dir_x * (PI / 180))
	//	/ 10;
	//data->player_y += sin(data->dir_x * (PI / 180))
	//	/ 10;
	
	data->player_y -= temp_y;
	data->player_x -= temp_x;
	
}


void check_move(int keycode, t_data *data)
{
	double x = data->player_x;
	double y = data->player_y;
	if (keycode == FOWARD)
		move_foward(data);
	else if (keycode == BACKWARD)
		move_backward(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == LEFT)
		move_left(data);
	if (!data->map[(int)floor(data->player_y)][(int)floor(data->player_x)])
	{
		data->player_x = x;
		data->player_y = y;
	}

	if (data->map[(int)floor(data->player_y)][(int)floor(data->player_x)] == '1')
	{
			data->player_x = x;
			data->player_y = y;
	}

}

int player_move(int keycode, t_data *data)
{
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