/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:05:28 by aappleto          #+#    #+#             */
/*   Updated: 2023/08/31 15:05:48 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	c3d_error(char *error, int fd, char *line, t_map_info *map_info)
{
	printf("\e[1;31mERROR:\e[0m ");
	printf("%s\n", error);
	if (fd)
		close(fd);
	if (line)
		free(line);
	if (map_info->exist.NO_texture_path)
		free(map_info->NO_texture_path);
	if (map_info->exist.SO_texture_path)
		free(map_info->SO_texture_path);
	if (map_info->exist.WE_texture_path)
		free(map_info->WE_texture_path);
	if (map_info->exist.EA_texture_path)
		free(map_info->EA_texture_path);
	if (map_info->exist.map)
		free_map(map_info->map);
	exit (0);
}
