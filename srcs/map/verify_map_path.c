#include "../../includes/cub3D.h"

/*	prints an error mensage based on the number that it receives	*/
bool	print_error(int error_nbr)
{
	printf("ERROR:\n");
	if (error_nbr == ERROR_ARGUMENTS)
		printf(ERROR_ARGUMENTS_MSG "\n");
	else if (error_nbr == ERROR_CONTRUCTION)
		printf(ERROR_CONTRUCTION_MSG "\n");
	else if (error_nbr == ERROR_EXIST)
		printf(ERROR_EXIST_MSG "\n");
	else if (error_nbr == ERROR_EXTENSION)
		printf(ERROR_EXTENSION_MSG "\n");
	return (false);
}

static bool	verify_map_file_existance(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

static bool	verify_map_extension(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i] && file_name[i] != 46)
		i++;
	i++;
	if (file_name[i] != 98 || file_name[i + 1] != 101
		|| file_name[i + 2] != 114)
		return (false);
	return (true);
}

bool	verify_map_path(int ac, char **av)
{
	if (!(ac == 2 || ac == 3))
		return (print_error(ERROR_ARGUMENTS));
	if (!verify_map_file_existance(av[1]))
		return (print_error(ERROR_EXIST));
	if (!verify_map_extension(av[1]))
		return (print_error(ERROR_EXTENSION));
	return (true);
}