#include "../includes/cub3D.h"



int	exit_game(t_all *all)
{
	free_map(all->map.map);
	mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	exit (1);
	return (0);
}

static void	init_vars(char *mapPath, t_all *all)
{
	init_map(&all->map, define_map(mapPath));
	start_playerinfo(all);
}

void	create_minimap(t_all *all)
{
	init_mm_mlxvars(&all->mlx, all->map.width, all->map.height);
	all->player.img = create_squareimg(all->mlx.ptr, RGB_RED, 0.5);
	mlx_hook(all->mlx.win, ON_DESTROY, 0, exit_game, &all);
	mlx_loop_hook(all->mlx.ptr, loop_hook, &all);
	draw_minimap(&all);
}

void	start_game(char *mapPath, int draw_mm)
{
	t_all	all;

	init_vars(mapPath, &all);
	if (draw_mm)
		create_minimap(&all);
	else
	{
	}
	mlx_key_hook(all.mlx.win, key_hook, &all);
	mlx_loop(all.mlx.ptr);
}