#include "../../includes/cub3D.h"
#include <sys/wait.h>

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

void	raycasting(t_data *data)
{
	float cameraX = 0;
	int pixel = 0;
	while (pixel < SCREENW)
	{
		// calc ray position and direction
		cameraX = 2 * pixel / (float)SCREENW - 1;
		data->ray.ray_dir.x = data->player.view_dir.x + data->player.plane.x * cameraX;
		data->ray.ray_dir.y = data->player.view_dir.y + data->player.plane.y * cameraX;
		data->player.map_posX = (int)data->player.position.x;
		data->player.map_posY = (int)data->player.position.y;

		// calc initial step
		data->ray.delta.x = sqrt(1 + pow(data->ray.ray_dir.y, 2) / pow(data->ray.ray_dir.x, 2));
		data->ray.delta.y = sqrt(1 + pow(data->ray.ray_dir.x, 2) / pow(data->ray.ray_dir.y, 2));
		if (data->ray.ray_dir.x < 0)
		{
			data->ray.step.x = -1;
			data->ray.side_dist.x = (data->player.position.x - data->player.map_posX) * data->ray.delta.x;
		}
		else
		{
			data->ray.step.x = 1;
			data->ray.side_dist.x = (data->player.map_posX + 1.0 - data->player.position.x) * data->ray.delta.x;
		}
		if (data->ray.ray_dir.y < 0)
		{
			data->ray.step.y = -1;
			data->ray.side_dist.y = (data->player.position.y - data->player.map_posY) * data->ray.delta.y;
		}
		else
		{
			data->ray.step.y = 1;
			data->ray.side_dist.y = (data->player.map_posY + 1.0 - data->player.position.y) * data->ray.delta.y;
		}

		// step until finding wall
		int hit = 0; // 1 if wall is hit
		int side = 0; // 0 if horizontal wall is hit / 1 if vertical wall is hit
		while (hit == 0)
		{
			if (data->ray.side_dist.x < data->ray.side_dist.y)
			{
				data->ray.side_dist.x += data->ray.delta.x;
				data->player.map_posX += data->ray.step.x;
				side = 0;
			}
			else
			{
				data->ray.side_dist.y += data->ray.delta.y;
				data->player.map_posY += data->ray.step.y;
				side = 1;
			}
			if (data->map.map[data->player.map_posY][data->player.map_posX] == '1')
				hit = 1;
		}

		// 2d test
		if (pixel == 0)
		{
			data->player.start_map_posX = data->player.map_posX;
			data->player.start_map_posY = data->player.map_posY;
		}

		// calc wall height
		float	prep_wall_dist = 0;
		int		line_h = 0;
		if (side == 0)
			prep_wall_dist = fabs((data->player.map_posX - data->player.position.x + (1 - data->ray.step.x) / 2) / data->ray.ray_dir.x);
		else
			prep_wall_dist = fabs((data->player.map_posY - data->player.position.y + (1 - data->ray.step.y) / 2) / data->ray.ray_dir.y);
		// if (side == 0)
		// 	prep_wall_dist = data->ray.side_dist.x - data->ray.delta.x;
		// else
		// 	prep_wall_dist = data->ray.side_dist.y - data->ray.delta.y;
		line_h = (int)(SCREENH / prep_wall_dist);
		int start = -line_h / 2 + SCREENH / 2;
		if (start < 0)
			start = 0;
		int end = line_h / 2 + SCREENH / 2;
		if (end >= SCREENH)
			end = SCREENH - 1;
		//printf("start - %d | end - %d | pixel - %d\n", start, end, pixel);

		//paints entire line by each pixel 
		int j = 0;
		while (j < SCREENH)
		{
			if (j < start)
				my_pixel_put(data, pixel, j, create_trgb(0, 180, 180, 180));
			else if (j > end)
				my_pixel_put(data, pixel, j, create_trgb(0, 180, 180, 180));
			else
			{
				if (side == 0)
					my_pixel_put(data, pixel, j, create_trgb(0, 255, 0, 0));
				else
					my_pixel_put(data, pixel, j, create_trgb(0, 139, 0, 0));
			}
			j++;
		}
		pixel++;
	}
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line + x * (data->img.bits / 8));
	*(unsigned int *)dst = color;
}

void	paint_3d_scene(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx3d.ptr, SCREENW, SCREENH);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits, &data->img.line, &data->img.endian);
	raycasting(data);
	mlx_put_image_to_window(data->mlx3d.ptr, data->mlx3d.win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx3d.ptr, data->img.img);
}

int	loop_hook(t_data *data)
{
	static unsigned int	frames;
	t_position	old_position;

	frames++;
	if (!(frames % (10000 / REFRESH_RATE)))
	{
		

		if (data->keys_pressed.general)
		{
			paint_3d_scene(data);
			old_position = data->player.position;
			update_position(data);
			// printf("dirX : %f", data->player.dirX);
			// printf("x : %f | y : %f\n", data->player.position.x, data->player.position.y);
			if (check_colision(data->player.hitbox, data->map))
			{
				data->player.position = find_new_position(data->player.position, old_position, data->map);
				data->player.hitbox = define_player_hitbox(data->player.position);
			}





			//temp while we wanna see 2d
			paint_path(data);
			// t_position end;
			// end.x = data->player.position.x + 3 * cos(data->player.dirX);
			// end.y = data->player.position.x + 3 * sin(data->player.dirX);
			// draw_line(data, data->player.position, end);


			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, - FOV_RAD / 2 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, - FOV_RAD / 4 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, FOV_RAD / 2 , data->map.map));
			// draw_line(data, data->player.position, find_ray_colision(data->player.position, data->player.dirX, FOV_RAD / 4 , data->map.map));
			float a = (CAMERA_PLANE_SIZE / 2) / tan(FOV_RAD/2);
			t_position b;
			// t_position c;
			// t_position d;
			b.x = data->player.position.x - (a * sin(data->player.dirX))/32;
			b.y = data->player.position.y - (a * cos(data->player.dirX))/32;
			// c.x = b.x - ((CAMERA_PLANE_SIZE / 2) * sin(data->player.dirX + M_PI_2))/32;
			// c.y = b.y - ((CAMERA_PLANE_SIZE / 2) * cos(data->player.dirX + M_PI_2))/32;
			// d.x = b.x + ((CAMERA_PLANE_SIZE / 2) * sin(data->player.dirX + M_PI_2))/32;
			// d.y = b.y + ((CAMERA_PLANE_SIZE / 2) * cos(data->player.dirX + M_PI_2))/32;
			draw_line(data, data->player.position, b, create_trgb(0, 255, 255, 0));
			// draw_line(data, c, d);


			// rays 2d test
			t_position	ray1;
			t_position	ray2;
			ray1.x = (float)data->player.start_map_posX;
			ray1.y = (float)data->player.start_map_posY;
			ray2.x = (float)data->player.map_posX;
			ray2.y = (float)data->player.map_posY; 
			draw_line(data, data->player.position, ray1, create_trgb(0, 0, 255, 255));
			draw_line(data, data->player.position, ray2, create_trgb(0, 0, 255, 255));
		}
	}
	return (0);
}