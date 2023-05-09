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