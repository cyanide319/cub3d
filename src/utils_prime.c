/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:28:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/16 12:20:55 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

t_game	*get_t_game(void)
{
	static t_game	game;

	return (&game);
}

t_map	*get_t_map(void)
{
	static t_map	map;

	return (&map);
}

void	*ft_realloc_tab(char **ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	else if (size == 0)
	{
		free (ptr);
		return (NULL);
	}
	else
	{
		new_ptr = malloc(sizeof(char *) * size);
		if (new_ptr == NULL)
			return (NULL);
		ft_memcpy(new_ptr, ptr, sizeof(char *) * (size - 1));
		free_tab(&ptr);
		return (new_ptr);
	}
}

int	free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (1);
}

void	*free_tab(char ***ptab)
{
	char	**tab;

	if (!ptab || !(*ptab))
		return (NULL);
	tab = *ptab;
	tab--;
	while (*(++tab))
		free_ptr((void **)tab);
	free_ptr((void **)ptab);
	return (NULL);
}
