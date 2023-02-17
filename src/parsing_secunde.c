/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_secunde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:58 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/16 18:44:33 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	parse_line(char *str)
{
	int		ret;
	char	**split;

	ret = 0;
	split = ft_split(str, ' ');
	if (split[0][0] == 'n' || split[0][0] == 'N')
		ret = 1;
	else if (split[0][0] == 's' || split[0][0] == 'S')
		ret = 2;
	else if (split[0][0] == 'e' || split[0][0] == 'E')
		ret = 3;
	else if (split[0][0] == 'w' || split[0][0] == 'W')
		ret = 4;
	else if (split[0][0] == 'f' || split[0][0] == 'F')
		ret = 5;
	else if (split[0][0] == 'c' || split[0][0] == 'C')
		ret = 6;
	return (ret);
}

int	check_digit(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*format_string(char *str)
{
	char	**split;
	char	*ret;

	split = ft_split(str, ' ');
	if (split == NULL)
		return (NULL);
	ret = ft_strdup(split[1]);
	free_tab(&split);
	return (ret);
}

int	*split_rgb(char *str)
{
	int		*array;
	char	**split;
	char	**nb;

	array = malloc(sizeof(int) * 3);
	if (array == NULL)
		return (NULL);
	split = ft_split(str, ' ');
	nb = ft_split(split[1], ',');
	if (check_digit(nb) != 0)
	{
		free_tab(&split);
		free_tab(&nb);
		return (NULL);
	}
	array[0] = ft_atoi(nb[0]);
	array[1] = ft_atoi(nb[1]);
	array[2] = ft_atoi(nb[2]);
	free_tab(&split);
	free_tab(&nb);
	return (array);
}