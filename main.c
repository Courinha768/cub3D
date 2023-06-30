#include "cub3D.h"

int	main(int ac, char **av)
{
	char	**map;

	if (!verify_map_path(ac, av))
		return (1);
	map = define_map(av[1]);
	if (!verify_map_construction(map))
		return (1);
	cub3D(map);
	return (0);
}