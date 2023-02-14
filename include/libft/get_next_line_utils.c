/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:43:43 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/14 12:48:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr1(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str || *str == c)
	{
		if (*str == (char)c)
			return ((char *)str);
		++str;
	}
	return (NULL);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen1(s1) + ft_strlen1(s2) + 1));
	if (!buffer)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			buffer[i] = s1[i];
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[ft_strlen1(s1) + ft_strlen1(s2)] = '\0';
	free(s1);
	return (buffer);
}
