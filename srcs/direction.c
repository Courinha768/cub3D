#include "../includes/cub3D.h"

void	look_up(t_all *all)
{
	(void)all;
}

void	look_down(t_all *all)
{
	(void)all;
}

void	look_left(t_all *all)
{
	all->player.dirX += CAMERA_SPEED;
}

void	look_right(t_all *all)
{
	all->player.dirX -= CAMERA_SPEED;	
}