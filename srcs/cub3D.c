#include "../includes/cub3D.h"

static void	init_vars(char *mapPath, t_data *data)
{
	init_map(&data->map, define_map(mapPath));
	start_playerinfo(data);
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.up = 0;
	data->keys.down = 0;
	data->keys.left = 0;
	data->keys.right = 0;
}

void	start_game(char *mapPath, int draw_mm)
{
	t_data	data;

	init_vars(mapPath, &data);
	if (draw_mm)
		create_minimap(&data);
	else	{}
}