/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:28:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 16:07:27 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	in_char_set(char c, char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i])
	{
		if (char_set[i] == c)
			return (0);
		i++;
	}
	return (-1);
}

void	dont_look_here(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map->raw_map[j] != NULL)
	{
		map->raw_map[i] = map->raw_map[j];
		i++;
		j++;
	}
	map->raw_map[j] = NULL;
}

int	game_over(t_data *data, int exit_code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (exit_code != 0)
	{
		if (data->text_e.pointer != NULL)
			mlx_destroy_image(data->mlx, data->text_e.pointer);
		if (data->text_w.pointer != NULL)
			mlx_destroy_image(data->mlx, data->text_w.pointer);
		if (data->text_n.pointer != NULL)
			mlx_destroy_image(data->mlx, data->text_n.pointer);
		if (data->text_s.pointer != NULL)
			mlx_destroy_image(data->mlx, data->text_s.pointer);
	}
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	clear_structs(data, 0);
	exit(exit_code);
}

void	init_data(t_data *data, t_map *map)
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
