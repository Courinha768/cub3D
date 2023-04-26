#include "../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_img(t_all *all, void *img, int y, int x)
{
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, img, x, y);
}
