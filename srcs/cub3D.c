#include "../includes/cub3D.h"

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
	else	{}
}