/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:26:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/08 14:14:11 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	**ft_realloc_tab(char **ptr, size_t size)
{
	char	**new_ptr;

	if (ptr == NULL)
		return (ft_calloc(sizeof(char *), size));
	else if (size == 0)
	{
		free (ptr);
		return (NULL);
	}
	else
	{
		new_ptr = ft_calloc(sizeof(char *), (size + 1));
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
	return (0);
}

void	free_array(char	***tabp)
{
	int		i;
	char	**tab;

	i = 0;
	tab = *tabp;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
	*tabp = NULL;
}

void	*free_tab(char ***ptab)
{
	char	**tab;

	if (!ptab || !(*ptab))
		return (NULL);
	tab = *ptab;
	while (*(tab))
	{
		free_ptr((void **)tab);
		tab++;
	}
	free_ptr((void **)ptab);
	return (NULL);
}
