/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:26:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/17 17:59:10 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	**ft_realloc_tab(char **ptr, size_t size)
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
		ft_memcpy(new_ptr, ptr, sizeof(char *) * size);
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
	return (0);
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
