#include "../../includes/cub3D.h"

//minimapa
void	place_player(t_data *data, t_position position)
{
	put_img(data, data->player.img, position.x * 32, position.y * 32);
}