/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tertie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:06:47 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/17 18:14:58 by tbeaudoi         ###   ########.fr       */
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