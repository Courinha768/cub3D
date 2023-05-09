#include "../includes/cub3D.h"

int	exit_game(t_data *data)
{
	free_map(data->map.map);
	mlx_destroy_window(data->mm_mlx.ptr, data->mm_mlx.win);
	exit (1);
	return (0);
}

static void	init_vars(char *mapPath, t_data *data)
{
	init_map(&data->map, define_map(mapPath));
	start_playerinfo(data);
}

void	start_game(char *mapPath, int draw_mm)
{
	t_data	data;

	init_vars(mapPath, &data);
	if (draw_mm)
		create_minimap(&data);
	//mlx_hook(data.mm_mlx.win, ON_KEYDOWN, 0, key_press_hook, &data);
	mlx_key_hook(data.mm_mlx.win, key_hook, &data);
	mlx_loop(data.mm_mlx.ptr);
}