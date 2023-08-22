#include "../../includes/cub3D.h"

static float	find_player_direction(t_map_info map, t_position player_position)
{
	if (map.map[(int)player_position.y][(int)player_position.x] == 'W')
		return (M_PI);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'S')
		return (3 * M_PI_2);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'E')
		return (0);
	else if (map.map[(int)player_position.y][(int)player_position.x] == 'N')
		return (M_PI_2);
	else
		return (0);
}

static t_position	find_player_position(t_map_info map)
{
	t_position		temp_player_position;
	unsigned int	i;
	unsigned int	j;

	temp_player_position.x = -1;
	temp_player_position.y = -1;
	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while (++j < map.height)
		{
			if (map.map[j][i] == 'N' || map.map[j][i] == 'S'
				|| map.map[j][i] == 'E' || map.map[j][i] == 'W')
			{
				temp_player_position.x = (float)i + 0.46875;
				temp_player_position.y = (float)j + 0.46875;
				return (temp_player_position);
			}
		}
	}
	return (temp_player_position);
} 

t_player_info	define_player_info(t_map_info map)
{
	t_player_info	temp_player;

	temp_player.position = find_player_position(map);
	temp_player.dirX = find_player_direction(map, temp_player.position);
	temp_player.hitbox = define_player_hitbox(temp_player.position);
	temp_player.view_dir.x = cos(temp_player.dirX);
	temp_player.view_dir.y = sin(temp_player.dirX);
	temp_player.plane.x = -sin(temp_player.dirX);
	temp_player.plane.y = cos(temp_player.dirX);
	temp_player.map_posX = 0;
	temp_player.map_posY = 0;
	// printf("view_dir.x - %f | view_dir.y - %f\nplane.x - %f | plane.y - %f\n", temp_player.view_dir.x, temp_player.view_dir.y, temp_player.plane.x, temp_player.plane.y);
	return (temp_player);
}
