#include "../includes/cub3D.h"

void	move_front(t_all *all)
{
	all->player.pos.x += PLAYER_SPEED * sin(all->player.dirX);
	all->player.pos.y += PLAYER_SPEED * cos(all->player.dirX);
}

void	move_back(t_all *all)
{
	all->player.pos.x -= PLAYER_SPEED * sin(all->player.dirX);
	all->player.pos.y -= PLAYER_SPEED * cos(all->player.dirX);
}

void	move_left(t_all *all)
{
	all->player.pos.x += PLAYER_SPEED * cos(all->player.dirX);
	all->player.pos.y += PLAYER_SPEED * sin(all->player.dirX);
}

void	move_right(t_all *all)
{
	all->player.pos.x -= PLAYER_SPEED * cos(all->player.dirX);
	all->player.pos.y -= PLAYER_SPEED * sin(all->player.dirX);
}