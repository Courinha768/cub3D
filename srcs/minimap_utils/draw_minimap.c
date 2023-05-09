#include "../../includes/cub3D.h"

void	draw_minimap(t_data *data)
{
	int		j;
	int		i;

	data->whiteSquareImg = create_squareimg(data->mm_mlx.ptr, RGB_LIGHT_GREY, 1);
	data->whiteSquareImg2 = create_squareimg(data->mm_mlx.ptr, RGB_LIGHT_GREY, 0.5);
	i = -1;
	while (data->map.map[++i] && data->map.map[i][0])
	{
		j = -1;
		while (data->map.map[i][++j + 1])
		{
			if (data->map.map[i][j] != 49 && data->map.map[i][j])
				put_img(data, data->whiteSquareImg, i * MP_SSIZE, j * MP_SSIZE);
		}
	}
	place_player(data);
}