/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:17:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/16 12:14:34 by tbeaudoi         ###   ########.fr       */
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

int	get_map(t_game *game, t_map *map)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(game->fd);
	if (temp == NULL)
		return (print_error_n_free("Bad file", &temp));
	map->map = ft_calloc(sizeof(char *), 1);
	while (temp != NULL)
	{
		if (temp[0] != '\n')
		{
			map->map[i] = ft_strdup(temp);
			printf("%s", map->map[i]);
		}
		free(temp);
		temp = get_next_line(game->fd);
		if (temp != NULL && temp[0] != '\n')
		{
			map->map = ft_realloc_tab(map->map, i + 2);
			i++;
		}
	}
	close (game->fd);
	return (0);
}

int	open_map(t_game *game, char *argv)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd <= 0)
		return (print_error("Bad file"));
	return (0);
}

int	parsing(char *argv)
{
	t_map	*map;
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	map = ft_calloc(sizeof(t_map), 1);
	if (check_file_format(argv) < 0)
		return (print_error("Bad file format. Must be .cub"));
	if (open_map(game, argv) < 0 || get_map(game, map))
		return (-1);
	printf("parsing successful");
	exit (1);
	return (0);
}
