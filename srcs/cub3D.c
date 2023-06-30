#include "../cub3D.h"

void	cub3D(char **map)
{
	t_data	data;
	
	data.map = define_map_info(map);
	data.player = define_player_info(data.map);
	data.keys_pressed = init_keys_pressed();
	if (DRAW_MINIMAP)
		draw_minimap(&data);
	close_game(&data);
}