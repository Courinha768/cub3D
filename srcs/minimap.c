#include "../includes/cub3D.h"

void	place_player(t_all *all)
{
	int	y;
	int	x;

	y = all->player.pos.y * MP_SSIZE + MP_SSIZE / 4;
	x = all->player.pos.x * MP_SSIZE + MP_SSIZE / 4;
	put_img(all, all->player.img, y, x);
}



void	draw_miniMap(t_all *all)
{
	int		j;
	int		i;

	all->whiteSquareImg = create_colorImage(all, create_trgb(PATH_COLOR));
	all->whiteSquareImg2 = create_colorImage2(all, create_trgb(PATH_COLOR));
	i = -1;
	while (all->map.map[++i] && all->map.map[i][0])
	{
		j = -1;
		while (all->map.map[i][++j + 1])
		{
			if (all->map.map[i][j] != 49 && all->map.map[i][j])
				put_img(all, all->whiteSquareImg, i * MP_SSIZE, j * MP_SSIZE);
		}
	}
	place_player(all);
}