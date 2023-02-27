/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:28:33 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/27 13:31:20 by tbeaudoi         ###   ########.fr       */
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
