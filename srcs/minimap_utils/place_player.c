#include "../../includes/cub3D.h"

void	place_player(t_data *data)
{
	int	y;
	int	x;

	y = data->player.pos.y * MP_SSIZE + MP_SSIZE / 4;
	x = data->player.pos.x * MP_SSIZE + MP_SSIZE / 4;
	put_img(data, data->player.img, y, x);
}