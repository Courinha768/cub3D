#include "../../includes/cub3D.h"

void	place_player(t_data *data, t_position position)
{
	put_img(data, data->player.img, position.y * 32, position.x * 32);
}