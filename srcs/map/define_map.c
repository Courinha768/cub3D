#include "../../cub3D.h"

static char	**get_map(int fd, int lc, char **map)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = get_map(fd, (lc + 1), map);
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

	fd = open(file_path, O_RDONLY);
	map = get_map(fd, 0, NULL);
	close(fd);
	return (map);
}