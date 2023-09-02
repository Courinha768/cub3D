/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:56:35 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:57:39 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_map_info	map_info;
	int			fp_len;

	map_info.exist = init_info_bool();
	fp_len = ft_strlen(av[1]);
	if (ac != 2)
		c3d_error(NBR_ARGS, 0, NULL, &map_info);
	if (av[1][fp_len - 4] != '.' || av[1][fp_len - 3] != 'c'
		|| av[1][fp_len - 2] != 'u' || av[1][fp_len - 1] != 'b')
		c3d_error(INVALID_FILE_EXTENSION, 0, NULL, &map_info);
	map_info = parsing(av[1]);
	if (check_map_construction1(map_info)
		|| check_map_construction2(map_info)
		|| check_map_construction3(map_info)
		|| check_map_construction4(map_info))
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 0, NULL, &map_info);
	cub3d(map_info);
}

	// printf("NO: [%s]\n", map_info.no_texture_path);
	// printf("SO: [%s]\n", map_info.so_texture_path);
	// printf("WE: [%s]\n", map_info.we_texture_path);
	// printf("EA: [%s]\n\n", map_info.ea_texture_path);
	// int	i = -1;
	// while (map_info.map[++i])
	// 	printf("%s", map_info.map[i]);
	// printf("\n");