#include "../includes/cub3D.h"

int	exit_game(t_all *all)
{
	free_map(all->map.map);
	mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	exit (1);
	return (0);
}

static void	start_game(char *mapPath, int draw_mm)
{
	t_all	all;

	init_map(&all.map, define_map(mapPath));
	start_playerInfo(&all);
	if (draw_mm)
	{
		init_mm_mlxVars(&all.mlx, all.map.width, all.map.height);
		all.player.img = create_SquareImg(all.mlx.ptr, RGB_RED, 0.5);
		mlx_hook(all.mlx.win, ON_DESTROY, 0, exit_game, &all);
		mlx_loop_hook(all.mlx.ptr, loopHook, &all);
		draw_miniMap(&all);
	}
	else
	{
	}
	mlx_key_hook(all.mlx.win, key_hook, &all);
	mlx_loop(all.mlx.ptr);
}

int	main(int ac, char **av)
{
	int		verify_value;

	verify_value = verify(ac, av);
	if (verify_value)
		return (print_error(verify_value));
	start_game(av[1], 1);
	return (0);
}
