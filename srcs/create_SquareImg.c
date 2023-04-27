#include "../includes/cub3D.h"

static void	paint_square(t_img_info	*img_info, int color, float size)
{
	int	pixel;
	int	y;
	int	x;

	y = -1;
	while (y++ < MP_SSIZE * size)
	{
		x = -1;
		while (x++ < MP_SSIZE * size)
		{
			pixel = (y * img_info->line_bytes) + (x * 4);
			if (img_info->endian == 1)
			{
				img_info->buffer[pixel + 0] = (color >> 24);
				img_info->buffer[pixel + 1] = (color >> 16) & 0xFF;
				img_info->buffer[pixel + 2] = (color >> 8) & 0xFF;
				img_info->buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (img_info->endian == 0)
			{
				img_info->buffer[pixel + 0] = (color) & 0xFF;
				img_info->buffer[pixel + 1] = (color >> 8) & 0xFF;
				img_info->buffer[pixel + 2] = (color >> 16) & 0xFF;
				img_info->buffer[pixel + 3] = (color >> 24);
			}
		}
	}
}

/*	Creates an image and paints a square of porportions "size" with "color"	*/
void	*create_squareimg(void	*mlx_ptr, int color, float size)
{
	void		*img;
	t_img_info	info;

	img = mlx_new_image(mlx_ptr, MP_SSIZE * size, MP_SSIZE * size);
	info.buffer = mlx_get_data_addr(img, &info.pixel_bits, &info.line_bytes,
			&info.endian);
	paint_square(&info, color, size);
	return (img);
}
