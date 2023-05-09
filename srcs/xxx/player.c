#include "../../includes/cub3D.h"

static t_position	find_playerposition(t_mapInfo *map)
{
	t_position		player_position;
	unsigned int	i;
	unsigned int	j;

	player_position.x = -1;
	player_position.y = -1;
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			if (map->map[j][i] == 'N' || map->map[j][i] == 'S'
				|| map->map[j][i] == 'E' || map->map[j][i] == 'W')
			{
				player_position.x = (float)i + 0.5;
				player_position.y = (float)j + 0.5;
				return (player_position);
			}
		}
	}
	return (player_position);
}

void	start_playerinfo(t_data *data)
{
	data->player.pos = find_playerposition(&data->map);
	if (data->map.map[(int)data->player.pos.y][(int)data->player.pos.x] == 'N')
		data->player.dirX = M_PI;
	if (data->map.map[(int)data->player.pos.y][(int)data->player.pos.x] == 'S')
		data->player.dirX = 0;
	if (data->map.map[(int)data->player.pos.y][(int)data->player.pos.x] == 'E')
		data->player.dirX = 3 * M_PI_2;
	if (data->map.map[(int)data->player.pos.y][(int)data->player.pos.x] == 'W')
		data->player.dirX = M_PI_2;
}