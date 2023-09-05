/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:05:37 by aappleto          #+#    #+#             */
/*   Updated: 2023/09/02 19:49:08 by aappleto         ###   ########.fr       */
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

char	*get_next_valid_line(int fd)
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
	if (!str_isdigit(rgb_code_char[0]) || !str_isdigit(rgb_code_char[1])
		|| !str_isdigit(rgb_code_char[2]))
	{
		find_color_free_utils(new_line, rgb_code_char);
		c3d_error(INVALID_COLORS, 3, line, map_info);
	}
	rgb_code[0] = ft_atoi(rgb_code_char[0]);
	rgb_code[1] = ft_atoi(rgb_code_char[1]);
	rgb_code[2] = ft_atoi(rgb_code_char[2]);
	find_color_free_utils(new_line, rgb_code_char);
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
	if (parse_line_util(line, map_info, info, &not_xpm))
		(void)not_xpm;
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
		c3d_error(TOO_MUCH_INFO, 3, line, map_info);
	if (not_xpm)
		c3d_error(XPM, 3, line, map_info);
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
		if (!(line[0] == '1' || line[0] == ' ' || line[0] == '\n'))
			c3d_error(MAP_NOT_CONSTRUCTED_CORRECTLY, fd, line, &map_info);
		free(line);
		line = get_next_valid_line(fd);
	}
	close(fd);
	parsing_utils(file_path, &map_info);
	return (map_info);
}
