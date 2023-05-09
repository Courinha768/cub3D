#include "../../includes/cub3D.h"

int	exit_game(t_data *data)
{
	free_map(data->map.map);
	mlx_destroy_window(data->mm_mlx.ptr, data->mm_mlx.win);
	exit (1);
	return (0);
}

void	create_minimap(t_data *data)
{
	init_mm_mlxvars(&data->mm_mlx, data->map.width, data->map.height);
	data->player.img = create_squareimg(data->mm_mlx.ptr, RGB_RED, 0.5);
	mlx_hook(data->mm_mlx.win, ON_DESTROY, 0, exit_game, data);
	mlx_loop_hook(data->mm_mlx.ptr, loop_hook, data);
	mlx_key_hook(data->mm_mlx.win, key_hook, data);
	
	draw_minimap(data);
	mlx_loop(data->mm_mlx.ptr);
}