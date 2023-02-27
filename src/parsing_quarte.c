/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quarte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:39:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/27 13:46:57 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	copy_map(t_map *map)
{
	int	i;
	int	j;

	i = 7;
	while (map->raw_map[i] != NULL)
		i++;
	map->map = ft_calloc(sizeof(char *), (i - 6));
	map->y_max = i - 8;
	i = 7;
	j = 0;
	while (map->raw_map[i] != NULL)
	{
		map->map[j] = ft_strdup(map->raw_map[i]);
		i++;
		j++;
	}
	free_tab(&map->raw_map);
	return (0);
}

int	find_player(t_map *map)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (in_char_set(map->map[y][x], "NSEW") == 0)
			{
				if (flag == 1)
					return (-1);
				flag = 1;
				map->p_orientation = map->map[y][x];
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (in_char_set(map->map[y][x], " 10NSEW") < 0)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
