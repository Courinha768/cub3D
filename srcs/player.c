#include "../includes/cub3D.h"

int	same_position(t_position p1, t_position p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (1);
	return (0);
}

static t_position	find_playerPosition(t_mapInfo *map)
{
	t_position playerPosition;
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
			if (map->map[j][i] == 'N' || map->map[j][i] == 'S' || map->map[j][i] == 'E' || map->map[j][i] == 'W')
			{
				playerPosition.x = (float)i;
				playerPosition.y = (float)j;
				return (playerPosition);
			}
		}
	}
	return (playerPosition);
}

static void	*create_player_image(t_mlx mlx, int color)
{
	void		*img;
	t_img_info	info;
	int			pixel;
	int			black;

	img = mlx_new_image(mlx.ptr,  MP_SSIZE / 2, MP_SSIZE / 2);
	info.buffer = mlx_get_data_addr(img, &info.pixel_bits, &info.line_bytes, &info.endian);
	black = create_trgb(0, 100, 10, 10);
	for(int y = 0; y < MP_SSIZE / 2; ++y)
	{
		for(int x = 0; x < MP_SSIZE / 2; ++x)
		{
		    pixel = (y * info.line_bytes) + (x * 4);
		    if (info.endian == 1)
		    {
		        info.buffer[pixel + 0] = (black >> 24);
		        info.buffer[pixel + 1] = (black >> 16) & 0xFF;
		        info.buffer[pixel + 2] = (black >> 8) & 0xFF;
		        info.buffer[pixel + 3] = (black) & 0xFF;
		    }
		    else if (info.endian == 0)
		    {
		        info.buffer[pixel + 0] = (black) & 0xFF;
		        info.buffer[pixel + 1] = (black >> 8) & 0xFF;
		        info.buffer[pixel + 2] = (black >> 16) & 0xFF;
		        info.buffer[pixel + 3] = (black >> 24);
		    }
		}
	}
	for(int y = 1; y < MP_SSIZE / 2 - 1; ++y)
	{
		for(int x = 1; x < MP_SSIZE / 2 - 1; ++x)
		{
		    pixel = (y * info.line_bytes) + (x * 4);
		    if (info.endian == 1)
		    {
		        info.buffer[pixel + 0] = (color >> 24);
		        info.buffer[pixel + 1] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 3] = (color) & 0xFF;
		    }
		    else if (info.endian == 0)
		    {
		        info.buffer[pixel + 0] = (color) & 0xFF;
		        info.buffer[pixel + 1] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 3] = (color >> 24);
		    }
		}
	}
	return (img);
}

void	define_playerInfo(t_all *all)
{
	all->player.pos = find_playerPosition(&all->map);
	all->player.img = create_player_image(all->mlx, create_trgb(PLAYER_COLOR));
	if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'N')
		all->player.dirX = M_PI;
	else if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'S')
		all->player.dirX = 0;
	else if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'E')
		all->player.dirX = 3 * M_PI_2;
	else if (all->map.map[(int)all->player.pos.y][(int)all->player.pos.x] == 'W')
		all->player.dirX = M_PI_2;
}