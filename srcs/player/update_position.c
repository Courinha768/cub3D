#include "../../includes/cub3D.h"

void	update_position(t_data *data)
{

	if (data->keys_pressed.w)
		move_front(data);
	else if (data->keys_pressed.s)
		move_back(data);
	if (data->keys_pressed.d)
		move_right(data);
	else if (data->keys_pressed.a)
		move_left(data);
	if (data->keys_pressed.up)
		look_up(data);
	else if (data->keys_pressed.down)
		look_down(data);
	if (data->keys_pressed.right)
		look_right(data);
	else if (data->keys_pressed.left)
		look_left(data);
	data->player.hitbox = define_player_hitbox(data->player.position);
}