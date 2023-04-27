#include "../includes/cub3D.h"

int	print_error(int error_nbr)
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
	return (error_nbr);
}
