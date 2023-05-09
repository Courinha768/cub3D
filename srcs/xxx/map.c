#include "../../includes/cub3D.h"

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

char	**define_map(char *file_name)
{
	char	**map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	map = get_map(fd, 0, NULL);
	close(fd);
	return (map);
}

void	init_map(t_mapInfo *map, char **charMap)
{
	map->map = charMap;
	map->width = ft_strlen(charMap[0]);
	map->height = 0;
	while (map->map[map->height])
		map->height++;
}

int	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free((void *)map);
	return (1);
}