/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:01:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/10/07 14:49:41 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_count(char const *src, char sep)
{
	int	count;

	count = 0;
	if (!src)
		return (0);
	while (*src)
	{
		while (*src == sep)
			src++;
		if (*src != sep && *src)
			count++;
		while (*src != sep && *src)
			src++;
	}
	return (count);
}

char	**ft_split(char const *src, char sep)
{
	char		**spltd;
	int			i;
	const int	words = ft_count(src, sep);
	int			len;

	i = 0;
	if (!src)
		return (NULL);
	spltd = malloc(sizeof(char *) * (words + 1));
	if (!spltd)
		return (NULL);
	while (i < words)
	{
		while (*src && *src == sep)
			src++;
		if (ft_strchr(src, sep))
			len = ft_strchr(src, sep) - src;
		else
			len = ft_strlen(src);
		spltd[i] = ft_substr(src, 0, len);
		src += len;
		i++;
	}
	spltd[i] = NULL;
	return (spltd);
}
