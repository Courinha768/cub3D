#include "../../includes/cub3D.h"

void	draw_line(float angle, t_position starting_position, t_data *data)
{
	void	*red_pixel;
	int		a;

	red_pixel = create_squareimg(data->mlx.ptr, RGB_RED, 1);
	a = 0;
	while(a++ < 200)
	{
		put_img(data, red_pixel, starting_position.x * 32 - (a * sin(angle)),
			starting_position.y * 32 - (a * cos(angle)));
	}
}