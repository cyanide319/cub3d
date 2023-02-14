/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:16:40 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/02/14 12:48:22 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// pull line from stash before the /n
char	*stash_to_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen1(stash) + 1));
	if (!line)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// free stash before the /n
// take the rest of the buffer after /n and put it back in stash
char	*free_stash(char *stash)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (ft_strlen1(stash) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	while (stash[i])
		buffer[j++] = stash[i++];
	buffer[j] = '\0';
	free (stash);
	return (buffer);
}

// read -> stash
// stash -> line
// return line
// free stash
// all over again until NULL
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			processed;

	processed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (!ft_strchr1(stash, '\n') && processed != 0)
	{
		processed = read(fd, line, BUFFER_SIZE);
		if (processed == -1)
		{
			free(line);
			return (NULL);
		}
		line[processed] = '\0';
		stash = ft_strjoin1(stash, line);
	}
	free (line);
	line = stash_to_line(stash);
	stash = free_stash(stash);
	return (line);
}
