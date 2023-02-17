/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/17 17:54:10 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	print_error(t_game *game, t_map *map, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (clear_structs(game, map, -1));
}

int	clear_structs(t_game *game, t_map *map, int exit_code)
{
	free_ptr((void **)map->wall_no);
	free_ptr((void **)map->wall_so);
	free_ptr((void **)map->wall_ea);
	free_ptr((void **)map->wall_we);
	free_ptr((void **)map->color_ceil);
	free_ptr((void **)map->color_floor);
	if (map->raw_map != NULL)
		free_tab(&map->raw_map);
	if (map->map != NULL)
		free_tab(&map->map);
	if (map != NULL)
		free(map);
	if (game != NULL)
		free(game);
	return (exit_code);
}
