/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:05:37 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 17:42:13 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	verify_file_existance(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

static char	*get_next_valid_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (!ft_strncmp(line, "\n", 100))
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

static int	find_color(char *line, t_map_info *map_info)
{
	char	*new_line;
	char	**rgb_code_char;
	int		rgb_code[3];

	if (charnbr(line, ',') != 2)
		c3d_error(INVALID_COLORS, 3, line, map_info);
	new_line = ft_substr(line, 2, ft_strlen(line) - 3);
	rgb_code_char = ft_split(new_line, ',');
	rgb_code[0] = ft_atoi(rgb_code_char[0]);
	rgb_code[1] = ft_atoi(rgb_code_char[1]);
	rgb_code[2] = ft_atoi(rgb_code_char[2]);
	free(rgb_code_char[0]);
	free(rgb_code_char[1]);
	free(rgb_code_char[2]);
	free(rgb_code_char);
	free(new_line);
	if (rgb_code[0] < 0 || rgb_code[0] > 255
		|| rgb_code[1] < 0 || rgb_code[1] > 255
		|| rgb_code[2] < 0 || rgb_code[2] > 255)
		c3d_error(INVALID_COLORS, 3, line, map_info);
	return (create_trgb(0, rgb_code[0], rgb_code[1], rgb_code[2]));
}

static void	parse_line(char *line, t_map_info *map_info, t_map_info_bool *info)
{
	bool	not_xpm;

	not_xpm = false;
	if (!ft_strncmp(line, "NO ", 3) && !info->no_texture_path)
		parse_vars(line, &map_info->no_texture_path, &info->no_texture_path, &not_xpm);
	else if (!ft_strncmp(line, "SO ", 3) && !info->so_texture_path)
		parse_vars(line, &map_info->so_texture_path, &info->so_texture_path, &not_xpm);
	else if (!ft_strncmp(line, "WE ", 3) && !info->we_texture_path)
		parse_vars(line, &map_info->we_texture_path, &info->we_texture_path, &not_xpm);
	else if (!ft_strncmp(line, "EA ", 3) && !info->ea_texture_path)
		parse_vars(line, &map_info->ea_texture_path, &info->ea_texture_path, &not_xpm);
	else if (!ft_strncmp(line, "F ", 2) && !info->floor_color)
	{
		map_info->floor_color = find_color(line, map_info);
		map_info->exist.floor_color = true;
	}
	else if (!ft_strncmp(line, "C ", 2) && !info->ceiling_color)
	{
		map_info->ceiling_color = find_color(line, map_info);
		map_info->exist.ceiling_color = true;
	}
	else
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, line, map_info);
	if (not_xpm)
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, 3, line, map_info);
}

t_map_info	parsing(char *file_path)
{
	int				fd;
	char			*line;
	t_map_info		map_info;

	map_info.exist = init_info_bool();
	if (!verify_file_existance(file_path))
		c3d_error(FILE_DOESNT_EXIST, 0, NULL, &map_info);
	fd = open(file_path, O_RDONLY);
	line = get_next_valid_line(fd);
	while (!is_complete(map_info.exist) && line)
	{
		parse_line(line, &map_info, &map_info.exist);
		free(line);
		line = get_next_valid_line(fd);
	}
	while (line)
	{
		free(line);
		line = get_next_valid_line(fd);
	}
	close(fd);
	map_info.map = define_map(file_path);
	if (!map_info.map)
		c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, fd, line, &map_info);	
	map_info.exist.map = true;
	set_map_size(&map_info);
	texture_files_exist(&map_info);
	return (map_info);
}
