#include "../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_img(t_all *all, void *img, int y, int x)
{
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, img, x, y);
}

void	*create_colorImage(t_all *all, int color)
{
	void		*img;
	t_img_info	info;
	int			pixel;

	img = mlx_new_image(all->mlx.ptr,  MP_SSIZE, MP_SSIZE);
	info.buffer = mlx_get_data_addr(img, &info.pixel_bits, &info.line_bytes, &info.endian);
	for(int y = 0; y < MP_SSIZE; ++y)
	{
		for(int x = 0; x < MP_SSIZE; ++x)
		{
		    pixel = (y * info.line_bytes) + (x * 4);
		    if (info.endian == 1)
		    {
		        info.buffer[pixel + 0] = (color >> 24);
		        info.buffer[pixel + 1] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 3] = (color) & 0xFF;
		    }
		    else if (info.endian == 0)
		    {
		        info.buffer[pixel + 0] = (color) & 0xFF;
		        info.buffer[pixel + 1] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 3] = (color >> 24);
		    }
		}
	}
	return (img);
}

void	*create_colorImage2(t_all *all, int color)
{
	void		*img;
	t_img_info	info;
	int			pixel;

	img = mlx_new_image(all->mlx.ptr,  MP_SSIZE / 2, MP_SSIZE / 2);
	info.buffer = mlx_get_data_addr(img, &info.pixel_bits, &info.line_bytes, &info.endian);
	for(int y = 0; y < MP_SSIZE / 2; ++y)
	{
		for(int x = 0; x < MP_SSIZE / 2; ++x)
		{
		    pixel = (y * info.line_bytes) + (x * 4);
		    if (info.endian == 1)
		    {
		        info.buffer[pixel + 0] = (color >> 24);
		        info.buffer[pixel + 1] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 3] = (color) & 0xFF;
		    }
		    else if (info.endian == 0)
		    {
		        info.buffer[pixel + 0] = (color) & 0xFF;
		        info.buffer[pixel + 1] = (color >> 8) & 0xFF;
		        info.buffer[pixel + 2] = (color >> 16) & 0xFF;
		        info.buffer[pixel + 3] = (color >> 24);
		    }
		}
	}
	return (img);
}
