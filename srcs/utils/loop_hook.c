#include "../../cub3D.h"

t_position	find_new_position(t_position wanted_position, t_position old_position, t_map_info map)
{
	t_position new_position;

	new_position.x = wanted_position.x;
	new_position.y = old_position.y;
	if (!check_colision(define_player_hitbox(new_position), map))
		return (new_position);
	new_position.x = old_position.x;
	new_position.y = wanted_position.y;
	if (!check_colision(define_player_hitbox(new_position), map))
		return (new_position);
	new_position.x = old_position.x;
	new_position.y = old_position.y;
	return (new_position);
}

int	loop_hook(t_data *data)
{
	static unsigned int	frames;
	t_position	old_position;

	frames++;
	if (!(frames % (10000 / REFRESH_RATE)))
	{
		frames = 0;
		if (data->keys_pressed.general)
		{
			old_position = data->player.position;
			update_position(data);
			if (check_colision(data->player.hitbox, data->map))
			{
				data->player.position = find_new_position(data->player.position, old_position, data->map);
				data->player.hitbox = define_player_hitbox(data->player.position);
			}
			place_player(data, define_player_hitbox(old_position).tl_corner ,MAP_SQUARE);
			place_player(data, data->player.hitbox.tl_corner, PLAYER_SQUARE);
		}
	}
	return (0);
}