#include "../includes/cub3D.h"

static int	verify_map(char	*file_name)
{
	char	**map;

	map = define_map(file_name);
	if (sameSizeLines(map) || correct_char(map) || exists_player(map))
		return (free_map(map));
	free_map(map);
	return (0);
}

static int	verify_name(char *file_name)
{
	int	i;
	int	fd;

	i = 0;
	while (file_name[i] && file_name[i] != 46)
		i++;
	i++;
	if (file_name[i] != 98 || file_name[i + 1] != 101 || file_name[i + 2] != 114)
		return (2);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (3);
	close(fd);
	return (0);
}

int	verify(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (1);
	if (ac == 3)
		if (ft_strncmp(av[2], "test", 5))
			return (1);
	if (verify_name(av[1]))
		return (verify_name(av[1]));
	if (verify_map(av[1]))
		return (4);
	return (0);
}
