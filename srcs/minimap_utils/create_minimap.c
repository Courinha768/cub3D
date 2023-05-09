#include "../../includes/cub3D.h"

void	create_minimap(t_data *data)
{
	init_mm_mlxvars(&data->mm_mlx, data->map.width, data->map.height);
	data->player.img = create_squareimg(data->mm_mlx.ptr, RGB_RED, 0.5);
	mlx_hook(data->mm_mlx.win, ON_DESTROY, 0, exit_game, data);
	mlx_loop_hook(data->mm_mlx.ptr, loop_hook, data);
	draw_minimap(data);
}