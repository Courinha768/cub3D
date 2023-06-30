#include "../../cub3D.h"

void	place_player(t_data *data, t_position position, int img)
{
	if (img == PLAYER_SQUARE)
		put_img(data, data->player.img, position.x * 32, position.y * 32);
	else if (img == MAP_SQUARE)
		put_img(data, data->minimap_imgs.player_square, position.x * 32, position.y * 32);
}