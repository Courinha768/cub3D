/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:26:41 by aappleto          #+#    #+#             */
/*   Updated: 2022/04/27 22:26:44 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !gnl_strchr(backup, 10))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		buffer[read_bytes] = 0;
		backup = gnl_strjoin(backup, buffer);
	}
	free(buffer);
	if (read_bytes < 0)
		return (NULL);
	else
		return (backup);
}

static char	*get_line(char	*backup)
{
	char	*line;
	size_t	size;

	if (!*backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] - 10)
		size++;
	line = (char *)malloc(size + 2);
	if (!line)
		return (NULL);
	gnl_strlcpy(line, backup, size + 1);
	if (backup[size] == 10)
		line[size++] = 10;
	line[size] = 0;
	return (line);
}

static char	*remove_line(char *backup)
{
	int		i;
	int		j;
	char	*new_backup;

	i = 0;
	while (backup[i] && backup[i] - 10)
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(gnl_strlen(backup) - i + 1);
	if (!new_backup)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = 0;
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup = read_file(fd, backup);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_line(backup);
	return (line);
}