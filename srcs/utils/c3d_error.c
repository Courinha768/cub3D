/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:05:28 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 19:48:34 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	c3d_error(char *error, int fd, char *line, t_map_info *map_info)
{
	printf("\e[1;31mERROR:\e[0m ");
	printf("%s\n", error);
	if (fd)
	{
		while (line)
		{
			free(line);
			line = get_next_valid_line(fd);
		}
		close(fd);
	}
	if (line)
		free(line);
	if (map_info->exist.no_texture_path)
		free(map_info->no_texture_path);
	if (map_info->exist.so_texture_path)
		free(map_info->so_texture_path);
	if (map_info->exist.we_texture_path)
		free(map_info->we_texture_path);
	if (map_info->exist.ea_texture_path)
		free(map_info->ea_texture_path);
	if (map_info->exist.map)
		free_map(map_info->map);
	exit (0);
}
