#include "../../includes/cub3D.h"

void	place_player(t_all *all)
{
	int	y;
	int	x;

	y = all->player.pos.y * MP_SSIZE + MP_SSIZE / 4;
	x = all->player.pos.x * MP_SSIZE + MP_SSIZE / 4;
	put_img(all, all->player.img, y, x);
}