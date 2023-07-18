#include "../../includes/cub3D.h"

// void	draw_line(float angle, t_position starting_position, t_data *data)
// {
// 	void	*red_pixel;
// 	int		a;
// 	int		x;
// 	int		y;

// 	red_pixel = create_squareimg(data->mlx.ptr, create_trgb(0, 180, 180, 180), 1);
// 	a = 0;
// 	while(a++ < 200)
// 	{
// 		x = (int)floor((starting_position.x * 32 - ((a + 4) * sin(angle)))/32);
// 		y = (int)floor((starting_position.y * 32 - ((a + 4) * cos(angle)))/32);
// 		if (x >= 0 && y >= 0 && data->map.map[x][y] - 48)
// 			break ;
// 		put_img(data, red_pixel, starting_position.x * 32 - (a * sin(angle)),
// 			starting_position.y * 32 - (a * cos(angle)));
// 	}
// }

void	draw_line(t_data *data, t_position starting_position, t_position end_position)
{
	void	*pixel_img;
	t_position	delta;
	t_position	pixel;
	int		pixels;

	pixel_img = create_squareimg(data->mlx.ptr, create_trgb(0, 180, 180, 180), 1);
	delta.y = (end_position.y * 32 - starting_position.y * 32);
	delta.x = (end_position.x * 32 - starting_position.x * 32);
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.y /= pixels;
	delta.x /= pixels;
	pixel.x = starting_position.x * 32;
	pixel.y = starting_position.y * 32;
	while (pixels)
	{
	    put_img(data, pixel_img, pixel.x, pixel.y);
	    pixel.x += delta.x;
	    pixel.y += delta.y;
	    --pixels;
	}
}

t_position	find_ray_colision(t_position starting_position, float starting_angle, float angle, char** map)
{
	int		a;
	int		x;
	int		y;
	t_position	colision_point;

	a = 0;
	while(a++ < 200)
	{
		x = (int)floor((starting_position.x * 32 - ((a + 4) * sin(starting_angle + angle)))/32);
		y = (int)floor((starting_position.y * 32 - ((a + 4) * cos(starting_angle + angle)))/32);
		if (x >= 0 && y >= 0 && map[x][y] - 48)
			break ;
	}
	colision_point.x = (starting_position.x * 32 - ((a + 4) * sin(starting_angle + angle)))/32;
	colision_point.y = (starting_position.y * 32 - ((a + 4) * cos(starting_angle + angle)))/32;
	return (colision_point);
}