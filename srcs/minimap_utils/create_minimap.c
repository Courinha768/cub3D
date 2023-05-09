#include "../../includes/cub3D.h"

void	create_minimap(t_all *all)
{
	init_mm_mlxvars(&all->mlx, all->map.width, all->map.height);
	all->player.img = create_squareimg(all->mlx.ptr, RGB_RED, 0.5);
	mlx_hook(all->mlx.win, ON_DESTROY, 0, exit_game, all);
	mlx_loop_hook(all->mlx.ptr, loop_hook, all);
	draw_minimap(all);
}