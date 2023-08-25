#include "../../includes/cub3D.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_img *img, int x, int y)
{
	char	*dst;
	unsigned int color;

	dst = img->addr + (y * img->line + x * (img->bits / 8));
	color = *(unsigned int *)dst;
	return (color);
}