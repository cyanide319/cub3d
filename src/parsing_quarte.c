/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quarte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:39:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 16:03:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	copy_map(t_map *map)
{
	int	i;
	int	j;

	i = 6;
	while (map->raw_map[i] != NULL)
		i++;
	map->map = ft_calloc(sizeof(char *), (i - 5));
	map->y_max = i - 7;
	i = 6;
	j = 0;
	while (map->raw_map[i] != NULL)
	{
		map->map[j] = ft_strdup(map->raw_map[i]);
		i++;
		j++;
	}
	free_array(&map->raw_map);
	return (0);
}

int	find_player(t_map *map)
{
	int	x;
	int	y;
	int	flag;

	y = -1;
	flag = 0;
	while (map->map[++y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (in_char_set(map->map[y][x], "NSEW") == 0)
			{
				if (flag == 1)
					return (-1);
				flag = 1;
				map->player_y = y;
				map->player_x = x;
				map->p_orientation = map->map[y][x];
				map->map[y][x] = '0';
			}
			x++;
		}
	}
	return (flag);
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

int	check_img_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (-1);
	close (fd);
	return (0);
}

int	check_file_format(char *str)
{
	char	*comp;
	int		i;
	int		j;

	comp = ".cub";
	i = 0;
	j = 3;
	while (str[i] != '\0')
		i++;
	i--;
	while (j >= 0)
	{
		if (str[i] != comp[j])
			return (-1);
		i--;
		j--;
	}
	return (0);
}
