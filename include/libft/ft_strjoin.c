/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:02 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/12 20:20:18 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (slen = ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcat(str, (char *)s1, slen);
	ft_strlcat(str, (char *)s2, slen);
	return (str);
}
