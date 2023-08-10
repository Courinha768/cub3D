#include "../../includes/cub3D.h"

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
		printf("%d\n", data->keys_pressed.general);
		if (data->keys_pressed.general)
		{
			old_position = data->player.position;
			update_position(data);
			if (check_colision(data->player.hitbox, data->map))
			{
				data->player.position = find_new_position(data->player.position, old_position, data->map);
				data->player.hitbox = define_player_hitbox(data->player.position);
			}


			//temp while we wanna see minimap
			paint_path(data);
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, - FOV_RAD / 2 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, - FOV_RAD / 4 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, FOV_RAD / 2 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, FOV_RAD / 4 , data->map.map));
			// float a = (CAMERA_PLANE_SIZE / 2) / tan(FOV_RAD/2);
			// t_position b;
			// t_position c;
			// t_position d;
			// b.x = data->player.position.x - (a * sin(data->player.dirX))/32;
			// b.y = data->player.position.y - (a * cos(data->player.dirX))/32;
			// c.x = b.x - ((CAMERA_PLANE_SIZE / 2) * sin(data->player.dirX + M_PI_2))/32;
			// c.y = b.y - ((CAMERA_PLANE_SIZE / 2) * cos(data->player.dirX + M_PI_2))/32;
			// d.x = b.x + ((CAMERA_PLANE_SIZE / 2) * sin(data->player.dirX + M_PI_2))/32;
			// d.y = b.y + ((CAMERA_PLANE_SIZE / 2) * cos(data->player.dirX + M_PI_2))/32;
			// draw_line(data, data->player.position, b);
			// draw_line(data, c, d);

		}
	}
	return (0);
}