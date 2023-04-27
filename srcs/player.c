#include "../includes/cub3D.h"

static t_position	find_playerPosition(t_mapInfo *map)
{
	t_position		playerPosition;
	unsigned int	i;
	unsigned int	j;

	playerPosition.x = -1;
	playerPosition.y = -1;
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			if (map->map[j][i] == 'N' || map->map[j][i] == 'S'
				|| map->map[j][i] == 'E' || map->map[j][i] == 'W')
			{
				playerPosition.x = (float)i;
				playerPosition.y = (float)j;
				return (playerPosition);
			}
		}
	}
	return (playerPosition);
}

void	start_playerInfo(t_all *all)
{
	all->player.pos = find_playerPosition(&all->map);
	if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'N')
		all->player.dirX = M_PI;
	if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'S')
		all->player.dirX = 0;
	if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'E')
		all->player.dirX = 3 * M_PI_2;
	if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'W')
		all->player.dirX = M_PI_2;
}
