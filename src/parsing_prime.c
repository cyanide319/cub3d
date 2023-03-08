/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:17:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 15:43:02 by slord            ###   ########.fr       */
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

int	get_heigh(t_map *map)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(map->fd);
	if (temp == NULL)
		return (-1);
	while (temp != NULL)
	{
		if (temp[0] != '\n')
		{
			i++;
		}
		free(temp);
		temp = get_next_line(map->fd);
	}
	free(temp);
	close (map->fd);
	return (i);
}

int	get_map(t_map *map, char *argv)
{
	char	*temp;
	int		i;

	i = 0;
	map->raw_map = ft_calloc(sizeof(char *), get_heigh(map) + 1);
	open_map(map, argv);
	temp = get_next_line(map->fd);
	if (temp == NULL)
		return (-1);
	while (temp != NULL)
	{
		if (temp[0] != '\n')
		{
			map->raw_map[i] = temp;
			printf("%s", map->raw_map[i]);
			i++;
		}
		else
			free(temp);
		temp = get_next_line(map->fd);
	}
	printf("\n");
	return (close (map->fd));
}

int	open_map(t_map *map, char *argv)
{
	map->fd = open(argv, O_RDONLY);
	if (map->fd <= 0)
		return (-1);
	return (0);
}

int	get_map_data(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
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

int	parsing(t_data *data, char *argv)
{
	if (check_file_format(argv) < 0)
		return (print_error(data, "Bad file format. Must be .cub"));
	if (open_map(data->map, argv) < 0 || get_map(data->map, argv) < 0)
		return (print_error(data, "Bad file."));
	if (get_map_data(data->map) < 0 || parse_colors(data->map) < 0
		|| copy_map(data->map) < 0)
		return (print_error(data, "Your fucking map is fucking wrong."));
	if (check_texture_files(data->map) < 0)
		return (print_error(data, "Bad texture file."));
	if (check_frst_lines(data->map) < 0 || check_valid_map(data->map) < 0
		|| check_components(data->map) < 0)
		return (print_error(data, "Map invalid."));
	if (find_player(data->map) < 1)
		return (print_error(data, "Too many or not enough player."));
	return (0);
}
