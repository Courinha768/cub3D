#include "../includes/cub3D.h"

void	init_map(t_mapInfo *map, char **charMap)
{
	map->map = charMap;
	map->width = ft_strlen(charMap[0]);
	map->height = 0;
	while (map->map[map->height])
		map->height++;
}

void	init_mm_mlxvars(t_mlx *mlxVars, int width, int height)
{
	mlxVars->ptr = mlx_init();
	mlxVars->win = mlx_new_window(mlxVars->ptr, (width - 1)
			* MP_SSIZE, height * MP_SSIZE, GAME_NAME);
}
