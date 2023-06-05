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
	data->player.img = create_squareimg(data->mm_mlx.ptr, RGB_RED, PLAYER_PROPORTION);

	mlx_hook(data->mm_mlx.win, ON_DESTROY, 0, exit_game, data);
	mlx_hook(data->mm_mlx.win, ON_KEYDOWN, 1, key_press_hook, data);
	mlx_hook(data->mm_mlx.win, ON_KEYUP, 2, key_release_hook, data);
	mlx_loop_hook(data->mm_mlx.ptr, loop_hook, data);
	
	draw_minimap(data);
	mlx_loop(data->mm_mlx.ptr);
}