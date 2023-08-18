#include "../../includes/cub3D.h"

t_mlx	define_2d_mlx_vars(t_map_info	map_info)
{
	t_mlx	temp_mlx_vars;

	temp_mlx_vars.ptr = mlx_init();
	temp_mlx_vars.win = mlx_new_window(temp_mlx_vars.ptr, (map_info.width - 1)
			* 32, map_info.height * 32, GAME_NAME);
	return (temp_mlx_vars);
}