/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:09:32 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/19 14:23:01 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_stash(int fd, char **stash, int *byte_read)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	while (*byte_read > 0 && ft_has_line(*stash) == -1)
	{
		*byte_read = read(fd, buffer, BUFFER_SIZE);
		if (*byte_read < 0)
		{
			free(buffer);
			return ;
		}
		buffer[*byte_read] = '\0';
		*stash = ft_strcat(*stash, buffer);
		if (*stash == NULL)
		{
			free(buffer);
			return ;
		}
	}
	free(buffer);
}

static char	*ft_extract_line(char **stash)
{
	int		line_len;
	char	*line;
	char	*new_stash;

	if (!*stash || !**stash)
		return (NULL);
	line_len = ft_has_line(*stash);
	if (line_len == -1)
		line_len = ft_strlen(*stash);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, *stash, line_len);
	line[line_len] = '\0';
	new_stash = ft_strdup(*stash + line_len);
	if (new_stash == NULL || *new_stash == '\0')
	{
		free(new_stash);
		new_stash = NULL;
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;
	int			byte_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	byte_read = 1;
	ft_stash(fd, &stash[fd], &byte_read);
	if (stash[fd] != NULL)
		line = ft_extract_line(&stash[fd]);
	if (byte_read <= 0 && line == NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
