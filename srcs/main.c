#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	int		verify_value;

	verify_value = verify(ac, av);
	if (verify_value)
		return (print_error(verify_value));
	if (ac == 3 && !ft_strncmp(av[2], "draw_minimap", 13))
		start_game(av[1], 1);
	else
		start_game(av[1], 0);
	return (0);
}