/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 14:59:02 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	print_error(t_data *data, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (clear_structs(data, -1));
}

int	clear_structs(t_data *data, int exit_code)
{
	if (data->map->color_ceil != NULL)
		free(data->map->color_ceil);
	if (data->map->color_floor != NULL)
		free(data->map->color_floor);
	if (data->map->wall_no != NULL)
		free(data->map->wall_no);
	if (data->map->wall_so != NULL)
		free(data->map->wall_so);
	if (data->map->wall_ea != NULL)
		free(data->map->wall_ea);
	if (data->map->wall_we != NULL)
		free(data->map->wall_we);
	if (data->map->raw_map != NULL)
		free_tab(&data->map->raw_map);
	if (data->map->map != NULL)
		free_tab(&data->map->map);
	if (data->map != NULL)
		free(data->map);
	return (exit_code);
}
