#include "../../includes/cub3D.h"

void	init_mm_mlxvars(t_mlx *mlxVars, int width, int height)
{
	mlxVars->ptr = mlx_init();
	mlxVars->win = mlx_new_window(mlxVars->ptr, (width - 1)
			* MP_SSIZE, height * MP_SSIZE, GAME_NAME);
}