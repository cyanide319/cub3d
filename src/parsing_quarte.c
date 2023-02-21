/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quarte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:39:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/21 15:03:23 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	parse_colors(t_map *map)
{
	if (map->color_ceil == NULL || map->color_floor == NULL)
		return (-1);
	if (map->color_ceil[0] < 0 || map->color_ceil[0] > 255
		|| map->color_ceil[1] < 0 || map->color_ceil[1] > 255
		|| map->color_ceil[2] < 0 || map->color_ceil[2] > 255
		|| map->color_floor[0] < 0 || map->color_floor[0] > 255
		|| map->color_floor[1] < 0 || map->color_floor[1] > 255
		|| map->color_floor[2] < 0 || map->color_floor[2] > 255)
		return (-1);
	map->hex_color_ceil = (map->color_ceil[0] << 16)
		+ (map->color_ceil[1] << 8) + map->color_ceil[2];
	map->hex_color_floor = (map->color_floor[0] << 16)
		+ (map->color_floor[1] << 8) + map->color_floor[2];
	return (0);
}
