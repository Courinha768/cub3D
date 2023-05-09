#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	int		verify_value;

	verify_value = verify(ac, av);
	if (verify_value)
		return (print_error(verify_value));
	start_game(av[1], 1);
	return (0);
}