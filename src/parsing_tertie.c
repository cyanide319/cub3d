/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tertie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:07:44 by slord             #+#    #+#             */
/*   Updated: 2023/03/08 15:50:03 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_img_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (-1);
	close (fd);
	return (0);
}

int	check_texture_files(t_map *map)
{
	if (check_img_file(map->wall_no) < 0
		|| check_img_file(map->wall_so) < 0
		|| check_img_file(map->wall_ea) < 0
		|| check_img_file(map->wall_we) < 0)
		return (-1);
	return (0);
}

// int	check_frst_lines(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (map->map[0][i] != '\n' && map->map[0][i] != '\0'
// 			&& map->map[map->y_max][i] != '\n'
// 			&& map->map[map->y_max][i] != '\0')
// 	{
// 		if (map->map[0][i] == '0' || map->map[map->y_max][i] == '0')
// 			return (-1);
// 		i++;
// 	}
// 	i = -1;
// 	while (map->map[++i] != NULL)
// 	{
// 		if (map->map[i][0] == '0')
// 			return (-1);
// 	}
// 	return (0);
// }

int	check_frst_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\n' && map->map[0][i] != '\0'
			&& map->map[map->y_max][i] != '\n'
			&& map->map[map->y_max][i] != '\0')
	{
		if (in_char_set(map->map[0][i], "0NSEW") == 0
			|| in_char_set(map->map[map->y_max][i], "0NSEW") == 0)
			return (-1);
		i++;
	}
	i = -1;
	while (map->map[++i] != NULL)
	{
		if (in_char_set(map->map[i][0], "0NSEW") == 0)
			return (-1);
	}
	return (0);
}

// int	check_surrounding(t_map *map, int y, int x)
// {
// 	if (map->map[y][x + 1] != '0' && map->map[y][x + 1] != '1'
// 		&& map->map[y][x + 1] != 'N' && map->map[y][x + 1] != 'S'
// 		&& map->map[y][x + 1] != 'E' && map->map[y][x + 1] != 'W')
// 		return (-1);
// 	if (map->map[y][x - 1] != '0' && map->map[y][x - 1] != '1'
// 		&& map->map[y][x - 1] != 'N' && map->map[y][x - 1] != 'S'
// 		&& map->map[y][x - 1] != 'E' && map->map[y][x - 1] != 'W')
// 		return (-1);
// 	if (map->map[y + 1][x] != '0' && map->map[y + 1][x] != '1'
// 		&& map->map[y + 1][x] != 'N' && map->map[y + 1][x] != 'S'
// 		&& map->map[y + 1][x] != 'E' && map->map[y + 1][x] != 'W')
// 		return (-1);
// 	if (map->map[y - 1][x] != '0' && map->map[y - 1][x] != '1'
// 		&& map->map[y - 1][x] != 'N' && map->map[y - 1][x] != 'S'
// 		&& map->map[y - 1][x] != 'E' && map->map[y - 1][x] != 'W')
// 		return (-1);
// 	return (0);
// }

int	check_surrounding(t_map *map, int y, int x)
{
	if (in_char_set(map->map[y][x + 1], "01NSEW") < 0)
		return (-1);
	if (in_char_set(map->map[y][x - 1], "01NSEW") < 0)
		return (-1);
	if (in_char_set(map->map[y + 1][x], "01NSEW") < 0)
		return (-1);
	if (in_char_set(map->map[y - 1][x], "01NSEW") < 0)
		return (-1);
	return (0);
}

int	check_valid_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\n' && map->map[y][x] != '\0')
		{
			if (in_char_set(map->map[y][x], "0NSEW") == 0)
			{
				if (check_surrounding(map, y, x) < 0)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
