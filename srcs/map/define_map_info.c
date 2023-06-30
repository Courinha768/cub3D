#include "../../cub3D.h"

t_map_info	define_map_info(char **map)
{
	t_map_info	temp_map_info;

	temp_map_info.map = map;
	temp_map_info.height = 0;
	temp_map_info.width = 0;
	while (map[temp_map_info.height])
		temp_map_info.height++;
	while (map[0][temp_map_info.width])
		temp_map_info.width++;
	return (temp_map_info);
}