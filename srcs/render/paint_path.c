#include "../../includes/cub3D.h"

void	paint_path(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.map[++i] && data->map.map[i][0])
	{
		j = -1;
		while (data->map.map[i][++j + 1])
		{
			if (data->map.map[i][j] != 49 && data->map.map[i][j])
				put_img(data, data->minimap_imgs.map_square, i * 32 - 1, j * 32 - 1);
		}
	}
}