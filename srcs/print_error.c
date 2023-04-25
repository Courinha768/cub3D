#include "../includes/cub3D.h"

int	print_error(int value)
{
	write(2, "ERROR\n", 6);
	if (value == 1)
		write(1, "wrong number of arguments\n", 26);
	else if (value == 2)
		write(1, "file extension should be .ber\n", 30);
	else if (value == 3)
		write(1, "given file doesn't exist\n", 26);
	else if (value == 4)
		write(1, "map not correctly contructed\n", 30);
	return (0);
}