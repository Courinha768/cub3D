/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:16:49 by aappleto          #+#    #+#             */
/*   Updated: 2022/11/16 17:55:16 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	exit_game(t_all *all)
{
	free_map(all->map.map);
	mlx_destroy_window(all->mlx.ptr, all->mlx.win);
	exit (1);
	return (0);
}

static void	init_all(t_all *all, char **map)
{
	all->map.map = map;
	all->map.width = ft_strlen(map[0]);
	all->map.height = 0;
	while (all->map.map[all->map.height])
		all->map.height++;
	all->mlx.ptr = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.ptr, (all->map.width - 1) * MP_SSIZE, all->map.height * MP_SSIZE, GAME_NAME);
	define_playerInfo(all);
}

static void	create_miniMap(char **map)
{
	t_all	all;

	init_all(&all, map);
	draw_miniMap(&all);

	mlx_hook(all.mlx.win, 17, 1L << 17, exit_game, &all);
	mlx_loop(all.mlx.ptr);
}

int	main(int ac, char **av)
{
	int		verify_value;
	char	**map;

	verify_value = verify(ac, av);
	if (verify_value)
		return (print_error(verify_value));
	map = define_map(av[1]);
	create_miniMap(map);
	return (0);
}
