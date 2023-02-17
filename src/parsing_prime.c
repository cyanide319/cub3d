/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:17:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/17 18:13:51 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

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

// map->raw_map = ft_calloc(sizeof(char *), 2);
int	get_map(t_game *game, t_map *map)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(game->fd);
	if (temp == NULL)
		return (-1);
	while (temp != NULL)
	{
		if (temp[0] != '\n')
			map->raw_map[i] = ft_strdup(temp);
		free(temp);
		temp = get_next_line(game->fd);
		if (temp != NULL && temp[0] != '\n')
		{
			map->raw_map = ft_realloc_tab(map->raw_map, i + 2);
			i++;
		}
	}
	return (close (game->fd));
}

int	open_map(t_game *game, char *argv)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd <= 0)
		return (-1);
	return (0);
}

int	get_map_data(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 7)
	{
		j = parse_line(map->raw_map[i]);
		if (j == 1)
			map->wall_no = format_string(map->raw_map[i]);
		else if (j == 2)
			map->wall_so = format_string(map->raw_map[i]);
		else if (j == 3)
			map->wall_ea = format_string(map->raw_map[i]);
		else if (j == 4)
			map->wall_we = format_string(map->raw_map[i]);
		else if (j == 5)
			map->color_floor = split_rgb(map->raw_map[i]);
		else if (j == 6)
			map->color_ceil = split_rgb(map->raw_map[i]);
		else
			return (-1);
		i++;
	}
	return (0);
}

int	parsing(t_game *game, t_map *map, char *argv)
{
	if (check_file_format(argv) < 0)
		return (print_error(game, map, "Bad file format. Must be .cub"));
	if (open_map(game, argv) < 0 || get_map(game, map) < 0)
		return (print_error(game, map, "Bad file."));
	if (get_map_data(map) < 0)
		return (print_error(game, map, "Your fucking map is fucking wrong."));
	if (check_texture_files(map) < 0)
		return (print_error(game, map, "Bad texture file."));
	return (0);
}
