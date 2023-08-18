#include "../../includes/cub3D.h"

bool	check_colision(t_hitbox hitbox, t_map_info map_info)
{
	if (map_info.map[(int)hitbox.bl_corner.y][(int)hitbox.bl_corner.x] == 49)
		return (true);
	if (map_info.map[(int)hitbox.br_corner.y][(int)hitbox.br_corner.x] == 49)
		return (true);
	if (map_info.map[(int)hitbox.tl_corner.y][(int)hitbox.tl_corner.x] == 49)
		return (true);
	if (map_info.map[(int)hitbox.tr_corner.y][(int)hitbox.tr_corner.x] == 49)
		return (true);
	return (false);	
}