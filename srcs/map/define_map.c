/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:11:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/01 15:46:53 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	**get_map(int fd, int lc, char **map, bool *correct)
{
	char		*line;
	static bool	found_map;

	line = get_next_line(fd);
	while (line && line[0] != ' ' && line[0] != 49)
	{
		if (found_map)
			*correct = false;
		free(line);
		line = get_next_line(fd);
	}
	if (!found_map)
		found_map = true;
	if (line)
		map = get_map(fd, (lc + 1), map, correct);
	else if (!map)
		map = malloc(sizeof(char *) * (lc + 1));
	if (!map)
		return (NULL);
	map[lc] = line;
	return (map);
}

/*	Returns the map present in the file with the path file_path	*/
char	**define_map(char *file_path)
{
	char	**map;
	int		fd;
	bool	correct;

	correct = true;
	fd = open(file_path, O_RDONLY);
	map = get_map(fd, 0, NULL, &correct);
	close(fd);
	if (!correct)
		return (NULL);
	return (map);
}
