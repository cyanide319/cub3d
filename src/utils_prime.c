/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:28:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 14:10:31 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	in_char_set(char c, char *char_set)
{
	int	i;

	i = 0;
	while (char_set[i])
	{
		if (char_set[i] == c)
			return (0);
		i++;
	}
	return (-1);
}

void	dont_look_here(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map->raw_map[j] != NULL)
	{
		map->raw_map[i] = map->raw_map[j];
		i++;
		j++;
	}
	map->raw_map[j] = NULL;
}
